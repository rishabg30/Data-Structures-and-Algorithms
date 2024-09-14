#include <bits/stdc++.h>
using namespace std;
void toh_calculate(int n, int src, int helper, int dest)
{

    // Base Condition
    if (n == 1)
    {
        cout << "move disk " << n << " from rod " << src << " to rod " << dest << endl;
        return;
    }
    // Move n-1 disks first from src -> helper
    toh_calculate(n - 1, src, dest, helper);
    // Print the disk
    cout << "move disk " << n << " from rod " << src << " to rod " << dest << endl;
    toh_calculate(n - 1, helper, src, dest);
}
long long toh(int n, int from, int to, int aux)
{
    toh_calculate(n, from, aux, to);

    // Number of steps will be 2^N -1
    return pow(2, n) - 1;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2^N)
    Space complexity: O(N)
    */
    int n, from, to, aux;
    cin >> n >> from >> to >> aux;
    cout << toh(n, from, to, aux) << endl;
}