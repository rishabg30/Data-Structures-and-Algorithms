#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
    }
    return ans;
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
    cout << singleNumber(arr) << endl;
}