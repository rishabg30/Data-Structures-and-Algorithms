#include <bits/stdc++.h>
using namespace std;
void printTable(int curr_number, int n)
{
    if (curr_number > 10)
    {
        return;
    }
    cout << curr_number * n << endl;
    printTable(curr_number + 1, n);
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
    printTable(1, n);
}