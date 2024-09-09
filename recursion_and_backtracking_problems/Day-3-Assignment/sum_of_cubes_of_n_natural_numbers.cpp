#include <bits/stdc++.h>
using namespace std;
int sumOfCubes(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int smallans = sumOfCubes(n - 1);
    return (n * n * n) + smallans;
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
    cout << sumOfCubes(n) << endl;
}