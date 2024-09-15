#include <bits/stdc++.h>
using namespace std;
bool isValid(string str)
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
        // Opening brackets
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        // Closing brackets
        else if (str[i] == ')')
        {
            if (st.size() == 0 || st.top() != '(')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        else if (str[i] == '}')
        {
            if (st.size() == 0 || st.top() != '{')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        else
        {
            if (st.size() == 0 || st.top() != '[')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    if (st.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    cout << isValid(str) << endl;
}