#include <bits/stdc++.h>
using namespace std;
void print1ToN(int curr_count, int n)
{
    if (curr_count > n)
    {
        return;
    }
    cout << curr_count << endl;
    print1ToN(curr_count + 1, n);
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
    print1ToN(1, n);
}