#include <bits/stdc++.h>
using namespace std;
pair<int, int> getSwappedNumbers(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
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
    int a, b;
    cin >> a >> b;
    pair<int, int> p = getSwappedNumbers(a, b);
    cout << p.first << " " << p.second << endl;
}