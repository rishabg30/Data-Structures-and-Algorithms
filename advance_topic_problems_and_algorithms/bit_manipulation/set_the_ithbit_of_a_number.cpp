#include <bits/stdc++.h>
using namespace std;
int set_ith_bit(int n, int ithBit)
{
    int mask = (1 << ithBit);
    n = n | mask;
    return n;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(1)
    Space complexity: O(1)
    */
    int n, ithBit;
    cin >> n >> ithBit;
    cout << set_ith_bit(n, ithBit) << endl;
}