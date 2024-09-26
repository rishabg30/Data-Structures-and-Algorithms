#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    int mask = (n & (n - 1));
    if (mask == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    cout << isPowerOfTwo(n) << endl;
}