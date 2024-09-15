#include <bits/stdc++.h>
using namespace std;
stack<int> insertAtBottom(stack<int> st, int x)
{
    vector<int> arr;
    while (st.size() != 0)
    {
        arr.push_back(st.top());
        st.pop();
    }
    arr.push_back(x);
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        st.push(arr[n - i - 1]);
    }
    return st;
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
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    int x;
    cin >> x;
    st = insertAtBottom(st, x);
    while (st.size() != 0)
    {
        cout << st.top() << endl;
        st.pop();
    }
}