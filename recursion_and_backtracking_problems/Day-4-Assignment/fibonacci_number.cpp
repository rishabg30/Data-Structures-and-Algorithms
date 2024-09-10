#include <bits/stdc++.h>
using namespace std;
int nthFibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
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
    cout << nthFibonacci(n) << endl;
}