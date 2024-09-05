#include <bits/stdc++.h>
using namespace std;
/*
Given a binary array nums and an integer k, return the maximum number
of consecutive 1's in the array if you can flip at most k 0's.

This question can be trimmed to this to solve it easily: Given a binary array
nums and an integer k, return the maximum length of array with k 0's in it.
*/
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size(), count_zeros = 0, curr_length = 0, max_length = 0;
    int sptr = 0, eptr = 0;

    while (eptr < n)
    {
        if (nums[eptr] == 0)
        {
            count_zeros++;
        }
        while (count_zeros > k)
        {
            if (nums[sptr] == 0)
            {
                count_zeros--;
            }
            sptr++;
        }
        curr_length = eptr - sptr + 1;
        max_length = max(max_length, curr_length);
        eptr++;
    }
    return max_length;
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
    cout << longestOnes(arr, k) << endl;
}