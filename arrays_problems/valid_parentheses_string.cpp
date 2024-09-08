#include <bits/stdc++.h>
using namespace std;
bool checkValidString(string s)
{
    int n = s.size();
    int open_bracket = 0, close_bracket = 0;

    for (int i = 0; i < n; i++)
    {
        // Iterating from start
        if (s[i] == '(' || s[i] == '*')
        {
            open_bracket++;
        }
        else
        {
            open_bracket--;
        }
        // Iterating from end
        if (s[n - i - 1] == ')' || s[n - i - 1] == '*')
        {
            close_bracket++;
        }
        else
        {
            close_bracket--;
        }
        if (open_bracket < 0 || close_bracket < 0)
        {
            return false;
        }
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
    Space complexity: O(1)
    */
    string s;
    cin >> s;
    cout << checkValidString(s) << endl;
}