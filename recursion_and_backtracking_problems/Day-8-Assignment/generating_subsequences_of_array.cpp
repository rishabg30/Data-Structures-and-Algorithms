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
void generatingSubsets(int startIdx, vector<int> &nums, vector<int> &ds,
                       vector<vector<int>> &ans)
{
    if (startIdx == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    // Add element in ds vector [pick]
    ds.push_back(nums[startIdx]);
    generatingSubsets(startIdx + 1, nums, ds, ans);
    // Do not add element in ds vector [not pick]
    ds.pop_back();
    generatingSubsets(startIdx + 1, nums, ds, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    int startIdx = 0;
    vector<vector<int>> ans;
    vector<int> ds;
    generatingSubsets(startIdx, nums, ds, ans);
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2^N)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans = subsets(arr);
    printArray_2D(ans);
}