#include <bits/stdc++.h>
using namespace std;
int search_element_function(int startIdx, int endIdx, vector<int> &nums, int target)
{
    if (startIdx > endIdx)
    {
        return -1;
    }
    int mid = (startIdx + endIdx) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }
    else if (nums[mid] < target)
    {
        return search_element_function(mid + 1, endIdx, nums, target);
    }
    else
    {
        return search_element_function(startIdx, mid - 1, nums, target);
    }
    return -1;
}
int search(vector<int> &nums, int target)
{
    int startIdx = 0, endIdx = nums.size() - 1;
    return search_element_function(startIdx, endIdx, nums, target);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(LogN)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << search(arr, target) << endl;
}