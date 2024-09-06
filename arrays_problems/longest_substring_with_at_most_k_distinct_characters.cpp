#include <bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    int n = str.size();
    int sptr = 0, eptr = 0, curr_length = 0, max_length = 0;
    map<char, int> mp;

    while (eptr < n)
    {
        mp[str[eptr]]++;

        // If there are more than k unique characters start reducing the window
        while (mp.size() > k)
        {
            mp[str[sptr]]--;
            if (mp[str[sptr]] == 0)
            {
                mp.erase(str[sptr]);
            }
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
    Space complexity: O(26)
    */
    string str;
    cin >> str;
    int k;
    cin >> k;
    cout << kDistinctChars(k, str) << endl;
}