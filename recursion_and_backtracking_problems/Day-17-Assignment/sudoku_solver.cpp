#include <bits/stdc++.h>
using namespace std;
void printArray_2D(vector<vector<char>> &arr)
{
    for (auto it : arr)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}
bool check(int num, vector<vector<char>> &board, int i, int j)
{
    char ch = '0' + num;
    // Checking at same row
    for (int col = 0; col < 9; col++)
    {
        if (board[i][col] == ch)
        {
            return 0;
        }
    }
    // Checking at same column
    for (int row = 0; row < 9; row++)
    {
        if (board[row][j] == ch)
        {
            return 0;
        }
    }
    // Checking at same 3*3 box
    int row = (i / 3) * 3;
    int col = (j / 3) * 3;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            if (board[a + row][b + col] == ch)
            {
                return 0;
            }
        }
    }
    return true;
}
bool sudoku_solver(int i, int j, vector<vector<char>> &board)
{
    // Base Condition
    if (i == 9)
    {
        return 1;
    }
    // This means we have checked that particular row, now move to next row
    if (j == 9)
    {
        return sudoku_solver(i + 1, 0, board);
    }
    // This means this block has already been filled, therefore move to next block
    if (board[i][j] != '.')
    {
        return sudoku_solver(i, j + 1, board);
    }
    // This means block is not filled, therefore we have 1-9 options of filling this block
    else
    {
        for (int num = 1; num <= 9; num++)
        {
            // number should not present in same row, same column and in that 3*3 block
            if (check(num, board, i, j) == true)
            {
                board[i][j] = '0' + num;

                // if this returns false it means, value can't be assigned. Assign a next value
                if (sudoku_solver(i, j + 1, board) == true)
                {
                    return true;
                }
                board[i][j] = '.';
            }
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    // sending start row, start column in the function
    sudoku_solver(0, 0, board);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    assuming each block has empty cells, therefore total empty blocks = n * n
    Time complexity: O(9 ^ (N * N))
    Space complexity: O(N * N)
    */
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    solveSudoku(arr);
    printArray_2D(arr);
}