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
void generateSubsequence_withSumK(int startIdx, vector<int> &arr, int k, int currSum,
                                  vector<int> &ds, vector<vector<int>> &ans)
{
    // Base Condition
    if (startIdx == arr.size())
    {
        if (currSum == k)
        {
            ans.push_back(ds);
        }
        return;
    }
    // Pick the element
    ds.push_back(arr[startIdx]);
    generateSubsequence_withSumK(startIdx + 1, arr, k, currSum + arr[startIdx], ds, ans);

    // Not pick the element
    ds.pop_back();
    generateSubsequence_withSumK(startIdx + 1, arr, k, currSum, ds, ans);
}
vector<vector<int>> generateSubsequence(vector<int> &arr, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    generateSubsequence_withSumK(0, arr, k, 0, ds, ans);
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
    Space complexity: O(N^2)
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
    vector<vector<int>> ans = generateSubsequence(arr, k);
    printArray_2D(ans);
}