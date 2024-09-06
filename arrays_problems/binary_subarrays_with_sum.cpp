#include <bits/stdc++.h>
using namespace std;
/*
Instead of finding number of non-empty subarrays with a sum goal, we can find
number of subarrays with atMost sum goal - number of subarrays with atMost sum goal-1 which
will give us number of subarrays with sum = goal
*/
int subarrays_with_atmost_sum(vector<int> &nums, int goal)
{
    int n = nums.size();
    int sptr = 0, eptr = 0, curr_sum = 0, count = 0;
    while (eptr < n)
    {
        curr_sum += nums[eptr];
        while (curr_sum > goal)
        {
            curr_sum -= nums[sptr];
            sptr++;
        }
        count += (eptr - sptr + 1);
        cout << eptr << " " << sptr << " " << count << endl;
        eptr++;
    }
    return count;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int n = nums.size();
    int x = 0, y = 0;
    x = subarrays_with_atmost_sum(nums, goal);
    if (goal > 0)
    {
        y = subarrays_with_atmost_sum(nums, goal - 1);
    }
    return x - y;
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int goal;
    cin >> goal;
    cout << numSubarraysWithSum(arr, goal) << endl;
}