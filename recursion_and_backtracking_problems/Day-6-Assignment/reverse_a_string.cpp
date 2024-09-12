#include <bits/stdc++.h>
using namespace std;
void reverse_string_function(int startIdx, int endIdx, string &str)
{
    if (startIdx >= endIdx)
    {
        return;
    }
    reverse_string_function(startIdx + 1, endIdx - 1, str);
    swap(str[startIdx], str[endIdx]);
}
string reverseString(string &str)
{
    int startIdx = 0, endIdx = str.size() - 1;
    reverse_string_function(startIdx, endIdx, str);
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
    cout << reverseString(str);
}