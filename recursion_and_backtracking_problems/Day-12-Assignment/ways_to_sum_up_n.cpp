#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int countWays_repetition(int arr[], int n, int target)
{
    // Base Condition
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        // Pick the element
        count += countWays_repetition(arr, n, target - arr[i]);
    }
    return count % mod;
}
int countWays(int arr[], int n, int target)
{
    return countWays_repetition(arr, n, target);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(very high) ~ will optimize it with DP
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << countWays(arr, n, target) << endl;
}