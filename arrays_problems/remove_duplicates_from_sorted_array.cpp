#include <bits/stdc++.h>
using namespace std;
int remove_duplicate(vector<int> &arr)
{
    int size = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[size] = arr[i];
            size++;
        }
    }
    return size;
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
    cout << remove_duplicate(arr) << endl;
}