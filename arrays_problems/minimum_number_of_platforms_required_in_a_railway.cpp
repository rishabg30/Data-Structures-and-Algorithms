#include <bits/stdc++.h>
using namespace std;
int findPlatform(vector<int> &arrival, vector<int> &departure)
{
    int n = arrival.size();
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int i = 0, j = 0, currPlatforms = 0, maxPlatforms = 0;

    while (i < n)
    {
        if (arrival[i] <= departure[j])
        {
            currPlatforms++;
            i++;
        }
        else
        {
            currPlatforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, currPlatforms);
    }
    return maxPlatforms;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2NLog(N))
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arrival(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arrival[i];
    }
    vector<int> departure(n);
    for (int i = 0; i < n; i++)
    {
        cin >> departure[i];
    }
    cout << findPlatform(arrival, departure) << endl;
}