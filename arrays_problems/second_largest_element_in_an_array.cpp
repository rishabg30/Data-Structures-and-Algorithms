#include <bits/stdc++.h>
using namespace std;
int print2largest(vector<int> &arr)
{
    int maxi = -1, second_maxi = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {
            second_maxi = maxi;
            maxi = arr[i];
        }
        else
        {
            if (arr[i] == maxi)
            {
                continue;
            }
            second_maxi = max(second_maxi, arr[i]);
        }
    }
    return second_maxi;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << print2largest(arr) << endl;
}