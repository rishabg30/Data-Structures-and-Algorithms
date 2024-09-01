#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
vector<int> leaders(int n, int arr[])
{
    vector<int> ans;
    ans.push_back(arr[n - 1]);

    int curr_right_max = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= curr_right_max)
        {
            ans.push_back(arr[i]);
            curr_right_max = max(curr_right_max, arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = leaders(n, arr);
    printArray_1D(ans);
}