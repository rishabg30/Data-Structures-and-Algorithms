#include <bits/stdc++.h>
using namespace std;
int clear_bit(int n, int ithBit)
{
    int mask = 1 << ithBit;
    mask = ~mask;

    n = n & mask;
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
    cout << clear_bit(n, ithBit) << endl;
}