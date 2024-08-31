#include <bits/stdc++.h>
using namespace std;

int pairWithMaxSum(vector<int> &arr)
{
    int n = arr.size(), max_sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        max_sum = max(max_sum, arr[i] + arr[i + 1]);
    }
    return max_sum;
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << pairWithMaxSum(arr) << endl;
}