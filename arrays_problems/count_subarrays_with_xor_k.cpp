#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int prefix_xor = 0, count_subarrays = 0;
    map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        prefix_xor ^= arr[i];

        int xor_with_prefix_xor_and_x = prefix_xor ^ x;
        count_subarrays += mp[xor_with_prefix_xor_and_x];

        mp[prefix_xor]++;
    }
    return count_subarrays;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(N)
    */

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    cout << subarraysXor(arr, x) << endl;
}