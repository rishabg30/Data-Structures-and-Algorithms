#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = (n * m - 1), ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int mid_row = mid / m, mid_col = mid % m;
        if (matrix[mid_row][mid_col] == target)
        {
            return true;
        }
        else if (matrix[mid_row][mid_col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
    Time complexity: O(Log(N * M))
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