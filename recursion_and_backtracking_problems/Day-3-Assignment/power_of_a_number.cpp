#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n)
{
    long long updated_n = n;
    if (updated_n == 0)
    {
        return 1.0;
    }

    // If n is negative, make n positive and x will become 1/x
    if (updated_n < 0)
    {
        x = 1 / x;
        updated_n = -1 * updated_n; // Make n positive for the recursion
    }
    double smallans = myPow(x, updated_n / 2);
    if (updated_n % 2 == 0)
    {
        return smallans * smallans;
    }
    else
    {
        return x * smallans * smallans;
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(Exponential)
    Space complexity: O(N)
    */
    double x;
    cin >> x;
    int n;
    cin >> n;
    cout << myPow(x, n) << endl;
}