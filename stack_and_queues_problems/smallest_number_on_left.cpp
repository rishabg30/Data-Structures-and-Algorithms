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
vector<int> leftSmaller(int n, int arr[])
{
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (st.size() > 0 && st.top() >= arr[i])
        {
            st.pop();
        }
        if (st.size() != 0)
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
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
    vector<int> ans = leftSmaller(n, arr);
    printArray_1D(ans);
}