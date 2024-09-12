#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int perfectSum_function(int startIdx, int n, int arr[], int sum)
{
    // Base Condition
    if (startIdx >= n)
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }
    int count = 0;
    // Pick the element
    count = (count + perfectSum_function(startIdx + 1, n, arr, sum - arr[startIdx])) % mod;

    // Not pick the element
    count = (count + perfectSum_function(startIdx + 1, n, arr, sum)) % mod;
    return count;
}
int perfectSum(int arr[], int n, int sum)
{
    int startIdx = 0;
    return perfectSum_function(startIdx, n, arr, sum);
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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    cout << perfectSum(arr, n, sum) << endl;
}