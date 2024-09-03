#include <bits/stdc++.h>
using namespace std;
int checkfn(int mid, vector<int> &nums)
{
    // Handling last index case explicitely
    int n = nums.size();
    if (mid + 1 == n)
    {
        return 1;
    }
    if (nums[mid] > nums[mid + 1])
    {
        return 1;
    }
    return 0;
}
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1, ans = -1;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        int check = checkfn(mid, nums);
        if (check == 1)
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
    cout << findPeakElement(arr) << endl;
}