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
void combinationSum_function(int startIdx, int n, vector<int> &arr, int target, vector<int> &ds,
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
    // Pick the element
    ds.push_back(arr[startIdx]);
    combinationSum_function(startIdx, n, arr, target - arr[startIdx], ds, ans);
    ds.pop_back();
    // Not pick the element
    combinationSum_function(startIdx + 1, n, arr, target, ds, ans);
}
vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> ans;
    vector<int> ds;
    combinationSum_function(0, n, arr, target, ds, ans);
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
    vector<vector<int>> ans = combinationSum(arr, target);
    printArray_2D(ans);
}