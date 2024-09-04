#include <bits/stdc++.h>
using namespace std;
bool check_fn(int curr_div, vector<int> &nums, int threshold)
{

    int n = nums.size(), curr_ans = 0;
    for (int i = 0; i < n; i++)
    {
        curr_ans += nums[i] / curr_div;
        if (nums[i] % curr_div != 0)
        {
            curr_ans += 1;
        }
        if (curr_ans > threshold)
        {
            return false;
        }
    }
    return true;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size(), ans = -1;
    // Defining the search space
    int low = 1, high = *max_element(nums.begin(), nums.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool valid_ans = check_fn(mid, nums, threshold);
        if (valid_ans == true)
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
    int threshold;
    cin >> threshold;
    cout << smallestDivisor(arr, threshold) << endl;
}