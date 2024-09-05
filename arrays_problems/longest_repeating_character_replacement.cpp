#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
    int n = s.size(), count_different_char = 0;
    int sptr = 0, eptr = 0, max_length = 0;
    vector<int> freq(26, 0);
    int max_char_count = 0;

    while (eptr < n)
    {
        freq[s[eptr] - 'A']++;
        max_char_count = max(max_char_count, freq[s[eptr] - 'A']);

        /*
        This check is necessary which will help us tell how many redundant
        characters we are still left with.
        */
        while ((eptr - sptr + 1) - max_char_count > k)
        {
            // Reduce the window size
            freq[s[sptr] - 'A']--;
            sptr++;
        }
        max_length = max(max_length, eptr - sptr + 1);
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
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << characterReplacement(s, k) << endl;
}