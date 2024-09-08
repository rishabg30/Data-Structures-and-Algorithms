#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums and an integer k, return the number of
good subarrays of nums. A good array is an array where the number of
different integers in that array is exactly k.

Instead find out:
x = countSubarrays with different integers atMost K
y = countSubarrays with different integers atMost K-1;
ans = x - y = countSubarrays with different integers equals K
*/
int countSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int sptr = 0, eptr = 0, count = 0;
    map<int, int> mp;

    while (eptr < n)
    {
        mp[nums[eptr]]++;

        // If map size is greater than K, start reducing the window
        while (mp.size() > k)
        {
            mp[nums[sptr]]--;
            if (mp[nums[sptr]] == 0)
            {
                mp.erase(nums[sptr]);
            }
            sptr++;
        }
        count += (eptr - sptr + 1);
        eptr++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int x = 0, y = 0;
    x = countSubarrays(nums, k);
    y = countSubarrays(nums, k - 1);
    if (k > 0)
    {
        return x - y;
    }
    else
    {
        return x;
    }
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
    cout << subarraysWithKDistinct(arr, k) << endl;
}