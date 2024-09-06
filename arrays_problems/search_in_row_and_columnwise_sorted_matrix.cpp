#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();

    /*
    We will start the search from 0th row's last column
    The idea is : if target > matrix[i][j] : then move downwards
    else move left sidewards
    */
    int x = 0, y = m - 1;
    while (x >= 0 && y >= 0 && x < n && y < m)
    {
        if (matrix[x][y] == target)
        {
            return true;
        }
        else if (matrix[x][y] < target)
        {
            // Move downwards
            x++;
        }
        else
        {
            // Move left sidewards
            y--;
        }
    }
    return false;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N + M)
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
    int target;
    cin >> target;
    cout << searchMatrix(arr, target) << endl;
}