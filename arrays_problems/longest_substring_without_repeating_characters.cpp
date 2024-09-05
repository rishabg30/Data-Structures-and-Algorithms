#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int n = s.size(), curr_length = 0, max_length = 0;
    int sptr = 0, eptr = 0;
    map<char, int> mp; // stores{char, freq}

    while (eptr < n)
    {
        mp[s[eptr]]++;
        // If we found duplicate, start reducing the window
        while (mp[s[eptr]] > 1)
        {
            mp[s[sptr]]--;
            sptr++;
        }
        curr_length = eptr - sptr + 1;
        max_length = max(max_length, curr_length);
        eptr++;
    }
    return max_length;
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
    cout << lengthOfLongestSubstring(s) << endl;
}