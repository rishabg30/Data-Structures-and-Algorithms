#include <bits/stdc++.h>
using namespace std;
int largest(vector<int> &arr)
{
    int max_element = -1e9;
    for (int i = 0; i < arr.size(); i++)
    {
        max_element = max(max_element, arr[i]);
    }
    return max_element;
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
    cout << largest(arr) << endl;
}