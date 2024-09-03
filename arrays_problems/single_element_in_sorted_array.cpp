#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    if (n == 1)
    {
        return nums[0];
    }
    // Important base cases
    // Think of scenario's when single element is present in 0th index or at last index
    if (nums[0] != nums[1])
    {
        return nums[0];
    }
    if (nums[n - 1] != nums[n - 2])
    {
        return nums[n - 1];
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        // Even number of elements till mid index
        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid - 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Odd number of elements till mid index
        else
        {
            if (nums[mid] == nums[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
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
    cout << singleNonDuplicate(arr) << endl;
}