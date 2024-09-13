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
void combinationSum2_function(int startIdx, int n, vector<int> &arr, int target, vector<int> &ds,
                              vector<vector<int>> &ans)
{
    // Base Condition
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    if (target < 0 || startIdx == n)
    {
        return;
    }
    for (int i = startIdx; i < arr.size(); ++i)
    {
        // Skip duplicates
        if (i > startIdx && arr[i] == arr[i - 1])
        {
            continue;
        }
        ds.push_back(arr[i]);
        combinationSum2_function(i + 1, n, arr, target - arr[i], ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    combinationSum2_function(0, n, arr, target, ds, ans);
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
    Space complexity: O(N ^ 2)
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
    vector<vector<int>> ans = combinationSum2(arr, target);
    printArray_2D(ans);
}