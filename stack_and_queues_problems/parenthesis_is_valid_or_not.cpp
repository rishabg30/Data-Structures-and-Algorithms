#include <bits/stdc++.h>
using namespace std;
bool is_valid_parenthesis(string &str)
{
    int n = str.size();
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            st.push(str[i]);
            continue;
        }
        // Opening bracket
        if (str[i] == '(')
        {
            st.push(str[i]);
        }
        // Closing bracket
        else
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
    }
    return (st.size() == 0) ? 1 : 0;
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
    string str;
    cin >> str;
    cout << is_valid_parenthesis(str) << endl;
}