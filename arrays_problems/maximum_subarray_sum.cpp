#include <bits/stdc++.h>
using namespace std;
// Kadane's algorithm

int maxSubArray(vector<int> &nums)
{
    int n = nums.size(), curr_sum = 0, max_sum = -1e9;
    for (int i = 0; i < n; i++)
    {
        curr_sum += nums[i];
        max_sum = max(max_sum, curr_sum);
        if (curr_sum < 0)
        {
            max_sum = max(max_sum, curr_sum);
            curr_sum = 0;
        }
    }
    return max_sum;
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
    cout << maxSubArray(arr) << endl;
}