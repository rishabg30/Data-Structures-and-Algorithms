#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &stations, int K, double mid)
{
    int station_count = 0;
    for (int i = 1; i < stations.size(); i++)
    {
        int numberInBetween = ((stations[i] - stations[i - 1]) / mid);
        if ((stations[i] - stations[i - 1]) == (mid * numberInBetween))
        {
            numberInBetween--;
        }
        station_count += numberInBetween;
        if (station_count > K)
        {
            return false;
        }
    }
    return true;
}
double findSmallestMaxDist(vector<int> &stations, int K)
{
    // Defining search space
    double low = 0;
    double high = stations[stations.size() - 1] - stations[0];
    double ans = 0;
    while ((high - low) > 1e-6)
    {
        double mid = low + (high - low) / 2.0;
        if (isPossible(stations, K, mid))
        {
            ans = mid;
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(NLogN)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << findSmallestMaxDist(arr, k) << endl;
}