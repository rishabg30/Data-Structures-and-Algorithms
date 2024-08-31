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
void reverse_arr(int si, int ei, vector<int> &nums)
{
    while (si <= ei)
    {
        swap(nums[si], nums[ei]);
        si++;
        ei--;
    }
}
void rotate(vector<int> &nums, int k)
{
    // In LC question it is mentioned for right rotate
    // We know how to rotate leftwise.
    // rightRotate = n - leftRotate

    int n = nums.size();

    // handling negative k values
    if (k < 0)
    {
        k = k + n;
    }
    k = (k % n);
    k = n - k; // for rightrotate

    reverse_arr(0, k - 1, nums);
    reverse_arr(k, n - 1, nums);
    reverse_arr(0, n - 1, nums);
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
    rotate(arr, k);
    printArray_1D(arr);
}