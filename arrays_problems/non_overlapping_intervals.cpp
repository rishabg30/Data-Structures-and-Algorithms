#include <bits/stdc++.h>
using namespace std;
static bool comp(vector<int> &a1, vector<int> &a2)
{
    return a1[1] < a2[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    // Sort the array on basis on increasing order of endInterval
    sort(intervals.begin(), intervals.end(), comp);

    int count = 0;
    int curr_start = intervals[0][0], curr_end = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] < curr_end)
        {
            // This interval has to be removed
            count++;
        }
        else
        {
            curr_start = intervals[i][0];
            curr_end = intervals[i][1];
        }
    }
    return count;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
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
    cout << eraseOverlapIntervals(arr);
}