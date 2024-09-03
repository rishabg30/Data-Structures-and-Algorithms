#include <bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int n)
{
    // In these type of questions we define search space
    long long int low = 0, high = n, ans = 0;

    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        if (mid * mid <= n)
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
    long long int n;
    cin >> n;
    cout << floorSqrt(n) << endl;
}