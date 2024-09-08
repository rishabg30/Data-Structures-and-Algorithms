#include <bits/stdc++.h>
using namespace std;
/*
Input: n = 6,
start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
*/
static bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}
int maxMeetings(int n, int start[], int end[])
{
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back({start[i], end[i]});
    }

    // {{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}}
    // sort the array in ascending order of endtime
    sort(arr.begin(), arr.end(), comp);

    int count = 1, curr_end_time = arr[0].second;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].first <= curr_end_time)
        {
            continue;
        }
        else
        {
            count++;
            curr_end_time = arr[i].second;
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
    Time complexity: O(NLogN)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    int start[n];
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    int end[n];
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    cout << maxMeetings(n, start, end);
}