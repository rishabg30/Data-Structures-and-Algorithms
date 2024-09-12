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
/*
Given a list arr of n integers, return sums of all subsets
in it. Output sums can be printed in any order.
*/
void subsetSums_function(int startIdx, vector<int> &arr, int currSum,
                         vector<int> &ans)
{
    // Base Condition
    if (startIdx == arr.size())
    {
        ans.push_back(currSum);
        return;
    }
    // Pick the element
    currSum += arr[startIdx];
    subsetSums_function(startIdx + 1, arr, currSum, ans);

    // Not pick the element
    currSum -= arr[startIdx];
    subsetSums_function(startIdx + 1, arr, currSum, ans);
}
vector<int> subsetSums(vector<int> arr, int n)
{
    int startIdx = 0;
    vector<int> ans;
    subsetSums_function(startIdx, arr, 0, ans);

    // Sort the result vector before returning
    sort(ans.begin(), ans.end());
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
    vector<int> ans = subsetSums(arr, n);
    printArray_1D(ans);
}