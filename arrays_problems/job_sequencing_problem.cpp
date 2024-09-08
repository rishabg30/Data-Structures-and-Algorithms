#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
static bool comp(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
{
    return p1.first > p2.first;
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size(), max_slots = 0;
    // {points,{startDate, endDate}}
    vector<pair<int, pair<int, int>>> arr;
    for (int i = 0; i < n; i++)
    {
        pair<int, pair<int, int>> curr_pair = {jobs[i][2], {jobs[i][0], jobs[i][1]}};
        arr.push_back(curr_pair);
        max_slots = max(max_slots, arr[i].second.second);
    }
    sort(arr.begin(), arr.end(), comp);
    vector<bool> max_slots_array(max_slots + 1, true);
    int countJobs = 0, maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_job_deadline = arr[i].second.second;

        // This question can be more optimized by removing this while() loop using DSU
        while (curr_job_deadline >= 1)
        {
            // In this deadline we can place our current job
            if (max_slots_array[curr_job_deadline] == true)
            {
                max_slots_array[curr_job_deadline] = false;
                countJobs++;
                maxProfit += arr[i].first;
                break;
            }
            curr_job_deadline--;
        }
    }
    return {countJobs, maxProfit};
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(NLogN + N * N)
    Space complexity: O(N)
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
    vector<int> ans = jobScheduling(arr);
    printArray_1D(ans);
}