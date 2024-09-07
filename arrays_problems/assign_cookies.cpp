#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size(), m = arr2.size();
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;
    while (i < n)
    {
        if (j >= m)
        {
            break;
        }
        int curr_max_content = arr2[j];
        if (arr1[i] <= curr_max_content)
        {
            i++;
        }
        j++;
    }
    return i;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(min(N,M))
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    cout << findContentChildren(arr1, arr2) << endl;
}