#include <bits/stdc++.h>
using namespace std;
/*
A continuous subarray is called nice if there are k odd numbers on it. we can find
number of subarrays with atMost k odd numbers - number of subarrays with atMost k -1 odd numbers which
will give us number of subarrays with k odd numbers
*/
int countNiceSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int sptr = 0, eptr = 0, count_odd_numbers = 0, countSubarrays = 0;

    while (eptr < n)
    {
        // Odd element encountered
        if (nums[eptr] & 1)
        {
            count_odd_numbers++;
        }
        while (count_odd_numbers > k)
        {
            if (nums[sptr] & 1)
            {
                count_odd_numbers--;
            }
            sptr++;
        }
        countSubarrays += (eptr - sptr + 1);
        eptr++;
    }
    return countSubarrays;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int x = 0, y = 0;
    x = countNiceSubarrays(nums, k);
    if (k > 0)
    {
        y = countNiceSubarrays(nums, k - 1);
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
    int k;
    cin >> k;
    cout << numberOfSubarrays(arr, k) << endl;
}