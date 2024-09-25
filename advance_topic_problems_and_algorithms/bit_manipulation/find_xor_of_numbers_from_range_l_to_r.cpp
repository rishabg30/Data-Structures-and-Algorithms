#include <bits/stdc++.h>
using namespace std;
int calculate_xor(int x)
{
    int xor_till_range = 0;
    if (x % 4 == 0)
    {
        xor_till_range = (x);
    }
    if (x % 4 == 1)
    {
        xor_till_range = (1);
    }
    if (x % 4 == 2)
    {
        xor_till_range = (x + 1);
    }
    if (x % 4 == 3)
    {
        xor_till_range = (0);
    }
    return xor_till_range;
}
int findXOR(int l, int r)
{
    // as r will always be greater than l, first compute xor from 1->r
    int xor_till_r = calculate_xor(r);
    // compute xor from 1->l-1 [as l to be included in one xor]
    int xor_till_l = calculate_xor(l - 1);

    // xor(l->r) will be xor (1->r) - xor(1->(l-1))
    return xor_till_r ^ xor_till_l;
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
    int l, r;
    cin >> l >> r;
    cout << findXOR(l, r) << endl;
}