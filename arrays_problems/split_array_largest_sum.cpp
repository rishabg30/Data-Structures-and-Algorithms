#include <bits/stdc++.h>
using namespace std;
bool checkfn(int maxSum, vector<int> &nums, int k)
{
    int n = nums.size(), curr_sum = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        if (curr_sum + nums[i] <= maxSum)
        {
            curr_sum += nums[i];
        }
        else
        {
            curr_sum = nums[i];
            count++;
        }
    }
    if (count > k)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    // Defining the search space
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0), ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool checkPossibleSubarray = checkfn(mid, nums, k);
        if (checkPossibleSubarray == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << splitArray(arr, k) << endl;
}