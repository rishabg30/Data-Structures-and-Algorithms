#include <bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size(), max_count_of_ones = 0, ans_index = -1;

    for (int i = 0; i < n; i++)
    {
        // Apply binary search in each row and find first occurence of 1
        int low = 0, high = m - 1, idx = -1, curr_count_of_ones = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[i][mid] == 1)
            {
                idx = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (idx == -1)
        {
            curr_count_of_ones = 0;
        }
        else
        {
            curr_count_of_ones = (m - idx);
        }
        if (curr_count_of_ones > max_count_of_ones)
        {
            max_count_of_ones = curr_count_of_ones;
            ans_index = i;
        }
    }
    return ans_index;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(NLogN)
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
    cout << rowWithMax1s(arr) << endl;
}