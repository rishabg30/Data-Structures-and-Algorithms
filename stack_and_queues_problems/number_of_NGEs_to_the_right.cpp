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
vector<int> count_NGE(int n, vector<int> &arr, int queries,
                      vector<int> &indices)
{
    vector<int> ans;
    for (int i = 0; i < queries; i++)
    {
        int element = arr[indices[i]], start_idx = indices[i], count = 0;
        for (int i = start_idx; i < n; i++)
        {
            if (element < arr[i])
            {
                count++;
            }
        }
        ans.push_back(count);
        count = 0;
    }
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N * Q)
    Space complexity: O(Q)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int queries;
    cin >> queries;
    vector<int> indices(n);
    for (int i = 0; i < queries; i++)
    {
        cin >> indices[i];
    }
    vector<int> ans = count_NGE(n, arr, queries, indices);
    printArray_1D(ans);
}