#include <bits/stdc++.h>
using namespace std;
int isPrime(int i, int n)
{
    // Base Cases
    if (n <= 2)
    {
        if (n == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (n % i == 0)
    {
        return false;
    }
    if (i * i > n)
    {
        return true;
    }
    return isPrime(i + 1, n);
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
    cout << isPrime(2, n) << endl;
}