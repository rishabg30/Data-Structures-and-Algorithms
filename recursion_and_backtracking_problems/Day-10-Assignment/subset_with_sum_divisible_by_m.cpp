#include <bits/stdc++.h>
using namespace std;
bool divisbleByK_function(int startIdx, vector<int> &arr, int currSum, int k)
{
    // Base Condition
    if (currSum > 0 && currSum % k == 0)
    {
        return true;
    }
    if (startIdx == arr.size())
    {
        return false;
    }

    // Pick the element
    if (divisbleByK_function(startIdx + 1, arr, currSum + arr[startIdx], k) == true)
    {
        return true;
    }
    // Not Pick the element
    if (divisbleByK_function(startIdx + 1, arr, currSum, k) == true)
    {
        return true;
    }
    return false;
}
int DivisibleByM(vector<int> &arr, int k)
{
    int startIdx = 0;
    return divisbleByK_function(startIdx, arr, 0, k);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2^N)
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
    cout << DivisibleByM(arr, k) << endl;
}