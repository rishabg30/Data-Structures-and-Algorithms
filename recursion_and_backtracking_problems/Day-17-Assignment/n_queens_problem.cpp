#include <bits/stdc++.h>
using namespace std;
void printArray_2D(vector<vector<string>> &arr)
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
/* M-1 */
bool checkDiagonals(int n, vector<string> &board, int curr_row, int curr_column)
{
    // No need to check below diagonals as we are placing queens row-wise

    // Upper Left Diagonal
    int r = curr_row, c = curr_column;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
        r--;
        c--;
    }
    // Upper Right Diagonal
    r = curr_row, c = curr_column;
    while (r >= 0 && c < n)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
        r--;
        c++;
    }
    return true;
}
void nQueen_function(int curr_row, int n, vector<string> &board,
                     vector<int> &column, vector<vector<string>> &ans)
{
    // Base Condition
    if (curr_row == n)
    {
        ans.push_back(board);
        return;
    }

    // Start putting queen
    for (int j = 0; j < n; j++)
    {
        if (column[j] == 0 && checkDiagonals(n, board, curr_row, j) == true)
        {
            // Queen Placed
            column[j] = 1;
            board[curr_row][j] = 'Q';
            nQueen_function(curr_row + 1, n, board, column, ans);

            // Unplace the queen to track other paths
            column[j] = 0;
            board[curr_row][j] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    // Initialized the board with empty '.'
    vector<string> board(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i].push_back('.');
        }
    }

    vector<int> column(n, 0);
    nQueen_function(0, n, board, column, ans);
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    finding out where queen can be placed takes N! time.
    In 0th row -> N places
    In 1st row -> (N-1) places
    In 2nd row -> (N-2) places
    .
    .
    TC-> N * (N-1) * (N-2) .... -> (N!)
    Time complexity: O(N!)
    Space complexity: O(N ^ 2)
    */
    int n;
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);
    printArray_2D(ans);
}