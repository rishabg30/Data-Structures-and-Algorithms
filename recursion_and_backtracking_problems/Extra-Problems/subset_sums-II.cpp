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
void subsets_formed(int startIdx, vector<int> &nums, vector<int> &ds,
                    vector<vector<int>> &ans)
{
    // Base Condition
    if (startIdx == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    // Pick the element
    // Skipping the duplicates
    ds.push_back(nums[startIdx]);
    subsets_formed(startIdx + 1, nums, ds, ans);

    while (startIdx + 1 < nums.size() && nums[startIdx + 1] == nums[startIdx])
    {
        startIdx++;
    }
    // Pop the element [for backtracking]
    ds.pop_back();

    // Not Pick the element
    subsets_formed(startIdx + 1, nums, ds, ans);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    int startIdx = 0;
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    subsets_formed(startIdx, nums, ds, ans);
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2 ^ N)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans = subsetsWithDup(arr);
    printArray_2D(ans);
}