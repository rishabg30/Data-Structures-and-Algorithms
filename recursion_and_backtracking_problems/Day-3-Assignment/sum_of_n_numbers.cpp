#include <bits/stdc++.h>
using namespace std;
int sum_of_n_numbers(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int smallAns = sum_of_n_numbers(n - 1);
    return n + smallAns;
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
    cout << sum_of_n_numbers(n);
}