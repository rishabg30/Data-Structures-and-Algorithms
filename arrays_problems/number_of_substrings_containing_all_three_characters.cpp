#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
    int n = s.size();
    int sptr = 0, eptr = 0, count = 0;
    map<char, int> mp;

    while (eptr < n)
    {
        mp[s[eptr]]++;

        /*
        If we have all three elements present in a map, try to guess how many subarrays
        will be there consisting of these elements till eptr index = (n - eptr)
        */
        while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
        {
            count += (n - eptr);
            mp[s[sptr]]--;
            sptr++;
        }
        eptr++;
    }
    return count;
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
    string s;
    cin >> s;
    cout << numberOfSubstrings(s) << endl;
}