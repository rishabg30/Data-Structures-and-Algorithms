#include <bits/stdc++.h>
using namespace std;
int winner(int n, int k)
{
    if (n == 1)
    {
        // If only 1 member is left, it is treated as 0
        return 0;
    }
    // competitors are of range 0...n-1

    int x = winner(n - 1, k);
    int y = (x + k) % n;

    return y;
}
int josephus(int n, int k)
{
    return winner(n, k) + 1; // 1 is added as it is 1 based numbers
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
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) << endl;
}