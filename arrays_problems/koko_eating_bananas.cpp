#include <bits/stdc++.h>
using namespace std;
bool check_fn(int currTimeSpeed, vector<int> &piles, int h)
{
    long long n = piles.size(), curr_time = 0;
    for (int i = 0; i < n; i++)
    {
        long long var_time = (piles[i] / currTimeSpeed);
        if (piles[i] % currTimeSpeed != 0)
        {
            var_time++;
        }
        curr_time = curr_time + var_time;
        if (curr_time > h)
        {
            return false;
        }
    }
    return true;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    long long n = piles.size();

    // Defining the search space
    long long low = 1, ans = -1;
    int high = *max_element(piles.begin(), piles.end());

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        bool check_possible_time = check_fn(mid, piles, h);
        if (check_possible_time == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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
    int h;
    cin >> h;
    cout << minEatingSpeed(arr, h) << endl;
}