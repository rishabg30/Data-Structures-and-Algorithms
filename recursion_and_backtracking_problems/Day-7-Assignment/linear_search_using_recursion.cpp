#include <bits/stdc++.h>
using namespace std;
int search_element_function(int startIdx, vector<int> &arr, int x)
{
    if (startIdx >= arr.size())
    {
        return -1;
    }
    if (arr[startIdx] == x)
    {
        return startIdx;
    }
    return search_element_function(startIdx + 1, arr, x);
}
int search(vector<int> &arr, int x)
{
    int startIdx = 0;
    return search_element_function(startIdx, arr, x);
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    cout << search(arr, x) << endl;
}