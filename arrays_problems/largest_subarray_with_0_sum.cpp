#include <bits/stdc++.h>
using namespace std;
int maxLen(vector<int> &arr, int n)
{
    // will maintain a map storing {prefix_sum, index}
    map<int, int> mp;
    mp.insert({0, -1});
    int prefix_sum = 0, curr_length = 0, max_length = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (mp.find(prefix_sum) != mp.end())
        {
            curr_length = i - mp[prefix_sum];
        }

        max_length = max(max_length, curr_length);
        mp.insert(make_pair(prefix_sum, i));
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
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxLen(arr, n) << endl;
}