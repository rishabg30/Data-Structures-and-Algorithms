#include <bits/stdc++.h>
using namespace std;
int count_consonents_function(int startIdx, string &str)
{
    if (startIdx == str.size())
    {
        return 0;
    }
    int countSmallAns = count_consonents_function(startIdx + 1, str);
    if (str[startIdx] != 'a' && str[startIdx] != 'e' && str[startIdx] != 'i' && str[startIdx] != 'o' && str[startIdx] != 'u')
    {
        countSmallAns = countSmallAns + 1;
    }
    return countSmallAns;
}
int countConsonants(string &str)
{
    int startIdx = 0;
    return count_consonents_function(startIdx, str);
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
    cout << countConsonants(str) << endl;
}