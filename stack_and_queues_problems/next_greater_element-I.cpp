#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<long long> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
vector<long long> nextLargerElement(vector<long long> &arr, int n)
{
    vector<long long> ans(n, -1);
    stack<long long> st;

    for (int i = n - 1; i >= 0; i--)
    {
        /* the topmost element is smaller than present index array element
        therefore pop this element out until we get a bigger element*/
        while (st.size() > 0 && arr[i] >= st.top())
        {
            st.pop();
        }
        // If the stack is not empty, the top element is the next greater element
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
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> ans = nextLargerElement(arr, n);
    printArray_1D(ans);
}