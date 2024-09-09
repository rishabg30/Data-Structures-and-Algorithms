#include <bits/stdc++.h>
using namespace std;
void printOddNumbers(int n)
{
    if (n <= 0)
    {
        return;
    }
    if (n & 1)
    {
        cout << n << endl;
    }
    printOddNumbers(n - 1);
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
    printOddNumbers(n);
}