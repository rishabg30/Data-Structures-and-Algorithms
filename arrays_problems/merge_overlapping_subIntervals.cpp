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
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    pair<int, int> initialPair = {intervals[0][0], intervals[0][1]};

    for (int i = 1; i < n; i++)
    {
        pair<int, int> currPair = {intervals[i][0], intervals[i][1]};
        int currPair_startPoint = intervals[i][0];
        int currPair_endPoint = intervals[i][1];

        // If currPair startPoint <= initialPair_EndPoint
        if (currPair_startPoint <= initialPair.second)
        {
            // Pairs will be merged
            pair<int, int> newMergedPair = {initialPair.first,
                                            max(initialPair.second, currPair_endPoint)};
            initialPair = newMergedPair;
            continue;
        }
        // Pair is not overlapping
        else
        {
            ans.push_back({initialPair.first, initialPair.second});
            initialPair = currPair;
        }
    }
    ans.push_back({initialPair.first, initialPair.second});
    return ans;
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
    vector<vector<int>> ans = merge(arr);
    printArray_2D(ans);
}