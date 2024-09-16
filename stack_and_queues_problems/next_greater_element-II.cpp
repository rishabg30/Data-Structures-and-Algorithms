#include <bits/stdc++.h>
using namespace std;
/* Next greater element + circular link */
void printArray_1D(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
vector<int> nextGreaterElements(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(arr[n - i - 1]);
    }

    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[i] >= st.top())
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
    Time complexity: O(2 * N)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = nextGreaterElements(arr);
    printArray_1D(ans);
}