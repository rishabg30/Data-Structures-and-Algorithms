#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size(), max_profit = 0;
    int min_day_rate = 1e9;
    for (int i = 0; i < n; i++)
    {
        min_day_rate = min(min_day_rate, prices[i]);
        if (prices[i] >= min_day_rate)
        {
            max_profit = max(max_profit, prices[i] - min_day_rate);
        }
    }
    return max_profit;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxProfit(arr) << endl;
}