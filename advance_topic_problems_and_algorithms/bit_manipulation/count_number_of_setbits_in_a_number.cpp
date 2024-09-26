#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1 == 1)
        {
            count++;
        }
        // right shift the number by 1
        n = n >> 1;
    }
    return count;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(number of bits)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
}