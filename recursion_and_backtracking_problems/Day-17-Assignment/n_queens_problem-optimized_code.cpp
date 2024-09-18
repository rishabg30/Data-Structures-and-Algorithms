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
/* M-2 */
void nQueen_function(int curr_row, int n, vector<string> &board,
                     vector<int> &column, vector<int> &leftDiagonal,
                     vector<int> &rightDiagonal, vector<vector<string>> &ans)
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
        /* For leftDiagonal : (n-1) + (row-col)
           For rightDiagonal : (row + col)
        */
        if (column[j] == 0 && leftDiagonal[n - 1 + j - curr_row] == 0 && rightDiagonal[j + curr_row] == 0)
        {
            // Queen Placed
            column[j] = 1;
            board[curr_row][j] = 'Q';
            leftDiagonal[n - 1 + j - curr_row] = 1;
            rightDiagonal[j + curr_row] = 1;
            nQueen_function(curr_row + 1, n, board, column, leftDiagonal, rightDiagonal, ans);

            // Unplace the queen to track other paths
            column[j] = 0;
            board[curr_row][j] = '.';
            leftDiagonal[n - 1 + j - curr_row] = 0;
            rightDiagonal[j + curr_row] = 0;
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
    vector<int> leftDiagonal(2 * n - 1, 0);
    vector<int> rightDiagonal(2 * n - 1, 0);
    nQueen_function(0, n, board, column, leftDiagonal, rightDiagonal, ans);
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