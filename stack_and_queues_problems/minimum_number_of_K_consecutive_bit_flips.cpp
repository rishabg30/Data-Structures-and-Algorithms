#include <bits/stdc++.h>
using namespace std;
int minKBitFlips(vector<int> &nums, int k)
{
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O()
    Space complexity: O()
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
    cout << minKBitFlips(arr, k) << endl;
}