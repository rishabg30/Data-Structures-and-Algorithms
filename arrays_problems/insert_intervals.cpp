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
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int x = newInterval[0], y = newInterval[1];
    vector<vector<int>> ans;
    bool inserted = false;

    for (int i = 0; i < intervals.size(); i++)
    {
        // If current interval ends before the new interval starts, add it directly to ans
        if (intervals[i][1] < newInterval[0])
        {
            ans.push_back({intervals[i][0], intervals[i][1]});
        }
        // If current interval starts after the new interval ends, add the new interval (if not added already), and then add the current interval
        else if (intervals[i][0] > newInterval[1])
        {
            if (inserted == false)
            {
                ans.push_back({x, y}); // Insert merged newInterval before continuing
                inserted = true;
            }
            ans.push_back({intervals[i][0], intervals[i][1]});
        }
        // Overlapping intervals: merge them
        else
        {
            x = min(x, intervals[i][0]); // Merge start time
            y = max(y, intervals[i][1]); // Merge end time
        }
    }
    // If new interval hasn't been added yet (e.g., it goes beyond all existing intervals)
    if (!inserted)
    {
        ans.push_back({x, y});
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
    Time complexity: O(N)
    Space complexity: O(N)
    */
    int n, m;
    cin >> n >> m;
    vector<vector<int>> intervals(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> intervals[i][j];
        }
    }
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> ans = insert(intervals, newInterval);
    printArray_2D(ans);

    return 0;
}
