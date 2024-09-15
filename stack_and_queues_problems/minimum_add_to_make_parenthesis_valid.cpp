#include <bits/stdc++.h>
using namespace std;
int minAddToMakeValid(string str)
{
    int n = str.size();
    int brackets_difference = 0, extra_closing_brackets = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            brackets_difference++;
        }
        else
        {
            if (brackets_difference == 0 && str[i] == ')')
            {
                extra_closing_brackets++;
            }
            else
            {
                brackets_difference--;
            }
        }
    }
    return abs(brackets_difference) + extra_closing_brackets;
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
    string str;
    cin >> str;
    cout << minAddToMakeValid(str) << endl;
}