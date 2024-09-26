#include <bits/stdc++.h>
using namespace std;
int remove_last_setBit(int n)
{
    return (n & (n - 1));
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
    int n;
    cin >> n;
    cout << remove_last_setBit(n) << endl;
}