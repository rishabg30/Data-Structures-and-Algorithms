#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int smallAns = factorial(n - 1);
    return n * smallAns;
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
    cout << factorial(n) << endl;
}