#include <bits/stdc++.h>
using namespace std;
int median(vector<vector<int>> &matrix, int R, int C)
{
    int min_element = INT_MAX;
    int max_element = INT_MIN;
    int ans = -1;

    // Step 1: Calculating the search space
    for (int i = 0; i < R; i++)
    {
        min_element = min(min_element, matrix[i][0]);
        max_element = max(max_element, matrix[i][C - 1]);
    }

    while (min_element <= max_element)
    {
        int mid = min_element + (max_element - min_element) / 2;
        int frequency = 0;

        // Now calculating frequency of elements smaller than or equal to mid
        for (int i = 0; i < R; i++)
        {
            frequency += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if (frequency >= ((R * C) + 1) / 2)
        {
            ans = mid;
            max_element = mid - 1;
        }
        else
        {
            min_element = mid + 1;
        }
    }
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    x denotes difference between max_element and min_element
    Time complexity: O(x * RLogC)
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
    cout << median(arr, n, m) << endl;
}