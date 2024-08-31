#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
    {
        return;
    }
    int index1 = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index1 = i;
            break;
        }
    }
    // This means array is decreasingly sorted
    if (index1 == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    int index2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > nums[index1])
        {
            index2 = i;
            break;
        }
    }
    swap(nums[index1], nums[index2]);
    reverse(nums.begin() + index1 + 1, nums.end());
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
    nextPermutation(arr);
    printArray_1D(arr);
}