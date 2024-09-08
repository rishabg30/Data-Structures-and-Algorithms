#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    int n = s.size(), m = t.size();
    if (m > n)
    {
        return "";
    }
    vector<int> freq(128, 0);

    // First put all characters of t string in freq array
    for (int i = 0; i < m; i++)
    {
        freq[t[i]]++;
    }

    int sptr = 0, eptr = 0, count = m, length = 1e9, start_idx = 0;
    while (eptr < n)
    {
        /*
        if freq[x] > 0, this means we require element
        if freq[x] == 0, this means we have element as required
        if(freq[x] < 0), this means we have extra elements
        */

        // We need this character, take it and decrease the count
        if (freq[s[eptr]] > 0)
        {
            count--;
        }
        freq[s[eptr]]--;

        while (count == 0)
        {
            int curr_length = eptr - sptr + 1;
            if (curr_length < length)
            {
                length = curr_length;
                start_idx = sptr;
            }
            if (freq[s[sptr]] == 0)
            {
                count++;
            }
            freq[s[sptr]]++;
            sptr++;
        }
        eptr++;
    }
    if (length == 1e9)
    {
        return "";
    }
    else
    {
        return s.substr(start_idx, length);
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
    Space complexity: O(128)
    */
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
}