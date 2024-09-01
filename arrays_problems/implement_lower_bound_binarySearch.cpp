#include <bits/stdc++.h>
using namespace std;
int findFloor(vector<long long> &v, long long n, long long x)
{
    long long low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (v[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
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
    Time complexity: O(LogN)
    Space complexity: O(1)
    */
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long x;
    cin >> x;
    cout << findFloor(arr, n, x) << endl;
}