#include <bits/stdc++.h>
using namespace std;
bool check_bit_is_set_or_not(int n, int ithBit)
{
    int mask = (1 << ithBit);
    if (n & mask)
    {
        return true;
    }
    return false;
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
    cout << check_bit_is_set_or_not(n, ithBit) << endl;
}