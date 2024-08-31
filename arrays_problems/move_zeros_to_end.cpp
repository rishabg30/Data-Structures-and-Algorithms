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
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int si = 0, ei = 0;
    while (ei < n)
    {
        if (nums[ei] != 0)
        {
            swap(nums[ei], nums[si]);
            si++;
        }
        ei++;
    }
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
    moveZeroes(arr);
    printArray_1D(arr);
}