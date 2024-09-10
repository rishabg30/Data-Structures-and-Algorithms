#include <bits/stdc++.h>
using namespace std;
long long countWays(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    long long way1 = countWays(n - 1);
    long long way2 = countWays(n - 2);
    long long way3 = countWays(n - 3);
    return way1 + way2 + way3;
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
    cout << countWays(n) << endl;
}