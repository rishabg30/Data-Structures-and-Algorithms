#include <bits/stdc++.h>
using namespace std;
long long fn(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
        {
            break;
        }
    }
    return ans;
}
int NthRoot(int n, int m)
{
    // Defining the search space
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long nth_Root_ans = fn(mid, n, m);
        if (nth_Root_ans == m)
        {
            return mid;
        }
        else if (nth_Root_ans < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(LogN)
    Space complexity: O(1)
    */
    int n, m;
    cin >> n >> m;
    cout << NthRoot(n, m) << endl;
}