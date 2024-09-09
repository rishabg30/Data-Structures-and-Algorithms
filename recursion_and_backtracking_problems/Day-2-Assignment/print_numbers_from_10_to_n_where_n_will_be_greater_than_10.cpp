#include <bits/stdc++.h>
using namespace std;
void printNumbers(int curr_number, int n)
{
    if (curr_number > n)
    {
        return;
    }
    if (curr_number > 10)
    {
        cout << curr_number << endl;
    }
    printNumbers(curr_number + 1, n);
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
    printNumbers(1, n);
}