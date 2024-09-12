#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum_equalToK(int startIdx, int currSum, int k, vector<int> &arr)
{
    // Base Condition
    if (startIdx >= arr.size())
    {
        if (currSum == k)
        {
            return true;
        }
        return false;
    }
    //  Pick the element
    if (isSubsetSum_equalToK(startIdx + 1, currSum + arr[startIdx], k, arr) == true)
    {
        return true;
    }

    // Not pick the element
    if (isSubsetSum_equalToK(startIdx + 1, currSum, k, arr) == true)
    {
        return true;
    }
    return false;
}
bool isSubsetPresent(int n, int k, vector<int> &arr)
{
    int startIdx = 0;
    return isSubsetSum_equalToK(startIdx, 0, k, arr);
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
    int k;
    cin >> k;
    cout << isSubsetPresent(n, k, arr) << endl;
}