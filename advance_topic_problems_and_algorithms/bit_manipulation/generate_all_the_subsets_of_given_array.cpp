#include <bits/stdc++.h>
using namespace std;
void printArray_2D(vector<vector<int>> &arr)
{
    for (auto it : arr)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}
// Power set algorithm
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();

    // Iterate till (2^n - 1) i.e (1 << n) - 1
    for (int num = 0; num <= ((1 << n) - 1); num++)
    {
        vector<int> ds;
        for (int bit = 0; bit < n; bit++)
        {
            if ((num & (1 << bit)) != 0)
            {
                ds.push_back(nums[bit]);
            }
        }
        ans.push_back(ds);
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
    Time complexity: O((2 ^ n) * n)
    Space complexity: O(N ^ 2)
    */
    vector<int> nums = {3, 2, 4};
    vector<vector<int>> ans = subsets(nums);
    printArray_2D(ans);
}