#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    // Base condition
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(log(min(a,b)))
    Space complexity: O(1)
    */
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}