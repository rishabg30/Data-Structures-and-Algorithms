#include <bits/stdc++.h>
using namespace std;
int countWays_repition(int startIdx, int n, int arr[], int target)
{
    // Base Condition
    if (target == 0)
    {
        return 1;
    }
    if (startIdx == n || target < 0)
    {
        return 0;
    }
    int count = 0;
    // Pick the element
    count += countWays_repition(startIdx, n, arr, target - arr[startIdx]);

    // Not pick the element
    count += countWays_repition(startIdx + 1, n, arr, target);
    return count;
}
int countWays(int arr[], int n, int target)
{
    int startIdx = 0;
    return countWays_repition(startIdx, n, arr, target);
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
    int target;
    cin >> target;
    cout << countWays(arr, n, target) << endl;
}