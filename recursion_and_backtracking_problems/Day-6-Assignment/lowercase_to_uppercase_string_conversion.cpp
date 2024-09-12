#include <bits/stdc++.h>
using namespace std;
void to_upper_function(int startIdx, string &str)
{
    if (startIdx == str.size())
    {
        return;
    }
    to_upper_function(startIdx + 1, str);
    str[startIdx] = 'A' + str[startIdx] - 'a';
    return;
}
string to_upper(string &str)
{
    int startIdx = 0;
    to_upper_function(startIdx, str);
    return str;
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
    cout << to_upper(str) << endl;
}