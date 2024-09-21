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
/* M-1 Using Priority Queue
    Time complexity: O(N * N)
    Space complexity: O(N)
*/
/*
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;

    // store {element, index} in priority queue
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({nums[i], i});
        // This is the time when our window will become >= k
        if (i >= (k - 1))
        {
            // Check if this top index needs to be removed or can be used in future window
            while (pq.size() > 0 && pq.top().second <= i - k)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
    }
    return ans;
}

*/
/* M-1 Using Deque
    Time complexity: O(N)
    Space complexity: O(N)
*/
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    // {will be storing indexes}
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;

    // First push k elements inside deque
    for (int i = 0; i < k - 1; i++)
    {
        if (dq.size() == 0)
        {
            dq.push_back(i);
        }
        else
        {
            // No need to store elements which are smaller
            while (dq.size() > 0 && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    for (int i = k - 1; i < n; i++)
    {
        // No need to store elements which are smaller
        while (dq.size() > 0 && nums[i] > nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (dq.front() <= i - k)
        {
            dq.pop_front();
        }
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vector<int> ans = maxSlidingWindow(arr, k);
    printArray_1D(ans);
}