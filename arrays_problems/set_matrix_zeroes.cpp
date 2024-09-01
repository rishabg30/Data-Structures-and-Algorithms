#include <bits/stdc++.h>
using namespace std;
void printArray_2D(vector<vector<int>> &arr)
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

/*
Space complexity: O(N + M)
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> row(n, 0), col(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int curr_row = i, curr_col = j;
            if (row[curr_row] == 1 || col[curr_col] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
*/

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    bool row = false, col = false;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            col = true;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            row = true;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 1; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (row == true)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col == true)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N * M)
    Space complexity: O(1)
    */
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    setZeroes(arr);
    printArray_2D(arr);
}