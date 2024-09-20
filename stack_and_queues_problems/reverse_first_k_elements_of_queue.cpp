#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    while (k--)
    {
        st.push(q.front());
        q.pop();
    }
    queue<int> modifiedQ;
    while (st.size() != 0)
    {
        modifiedQ.push(st.top());
        st.pop();
    }
    while (q.size() != 0)
    {
        modifiedQ.push(q.front());
        q.pop();
    }
    return modifiedQ;
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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    q = modifyQueue(q, k);
    while (q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
}