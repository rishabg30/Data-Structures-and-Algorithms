#include <bits/stdc++.h>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    int sptr = 0, eptr = 0, curr_length = 0, max_length = 0;
    map<int, int> mp; // store number with frequency

    while (eptr < n)
    {
        mp[fruits[eptr]]++;

        while (mp.size() > 2)
        {
            mp[fruits[sptr]]--;
            // If frequency of a number becomes zero, remove from the map
            if (mp[fruits[sptr]] == 0)
            {
                mp.erase(fruits[sptr]);
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
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << totalFruit(arr) << endl;
}