#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int prefix_sum = 0, count = 0;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        prefix_sum += nums[i];
        if (prefix_sum == k)
        {
            count++;
        }
        if (mp.find(prefix_sum - k) != mp.end())
        {
            count += mp[prefix_sum - k];
        }
        mp[prefix_sum]++;
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << subarraySum(arr, k) << endl;
}