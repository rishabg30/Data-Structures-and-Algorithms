#include <bits/stdc++.h>
using namespace std;
void forming_string(string str, stack<char> &st)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (st.size() == 0 && str[i] == '#')
        {
            continue;
        }
        if (str.size() == 0)
        {
            st.push(str[i]);
            continue;
        }
        if (str[i] == '#')
        {
            st.pop();
            continue;
        }
        st.push(str[i]);
    }
}
bool backspaceCompare(string s, string t)
{
    stack<char> st1, st2;
    forming_string(s, st1);
    forming_string(t, st2);

    if (st1.size() != st2.size())
    {
        return false;
    }

    while (st1.size() != 0)
    {
        if (st1.top() != st2.top())
        {
            return false;
        }
        st1.pop();
        st2.pop();
    }
    return true;
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
    string str1, str2;
    cin >> str1 >> str2;
    cout << backspaceCompare(str1, str2) << endl;
}