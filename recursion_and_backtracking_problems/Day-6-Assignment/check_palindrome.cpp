#include <bits/stdc++.h>
using namespace std;
int check_palindrome_function(int startIdx, int endIdx, string &str)
{
    if (startIdx >= endIdx)
    {
        return 1;
    }
    int smallAns = check_palindrome_function(startIdx + 1, endIdx - 1, str);
    if (smallAns == 1 && str[startIdx] == str[endIdx])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkPalindrome(string &str)
{
    int startIdx = 0, endIdx = str.size() - 1;
    return check_palindrome_function(startIdx, endIdx, str);
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
    cout << checkPalindrome(str) << endl;
}