#include <bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int arr[], int n, int k)
{
    // this question contains arr[i] both negatives and positives
    map<int, int> mp;
    int curr_sum = 0, max_length = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum == k)
        {
            max_length = max(max_length, i + 1);
        }
        if (mp.find(curr_sum - k) != mp.end())
        {
            max_length = max(max_length, i - mp[curr_sum - k]);
        }
        mp.insert(make_pair(curr_sum, i));
    }
    return max_length;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << lenOfLongSubarr(arr, n, k) << endl;
}