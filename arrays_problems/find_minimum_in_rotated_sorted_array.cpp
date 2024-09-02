#include <bits/stdc++.h>
using namespace std;
int check(int mid, vector<int> &nums)
{
    int n = nums.size();
    if (nums[mid] <= nums[n - 1])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1, ans_index = -1;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);

        // Designing of check function
        int val = check(mid, nums);

        // Can be our potential ans, store it and discard right area
        if (val == 1)
        {
            ans_index = mid;
            high = mid - 1;
        }
        // discard left area
        else
        {
            low = mid + 1;
        }
    }
    return nums[ans_index];
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(LogN)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findMin(arr) << endl;
}