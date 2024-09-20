#include <bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q)
{
    stack<int> st;
    while (q.size() != 0)
    {
        int x = q.front();
        q.pop();
        st.push(x);
    }
    while (st.size() != 0)
    {
        q.push(st.top());
        st.pop();
    }
    return q;
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
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    q = rev(q);
    while (q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
}