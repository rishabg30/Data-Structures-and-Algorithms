#include <bits/stdc++.h>
using namespace std;
bool check_fn(int mid, vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size(), consecutive_count = 0, count_bouquets = 0;
    for (int i = 0; i < n; i++)
    {
        if (mid >= bloomDay[i])
        {
            consecutive_count++;
        }
        else if (mid < bloomDay[i])
        {
            consecutive_count = 0;
        }
        if (consecutive_count == k)
        {
            count_bouquets++;
            consecutive_count = 0;
        }
    }
    if (count_bouquets >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size(), ans = -1;

    // Defining the search space
    int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool possible_to_make_bouquets = check_fn(mid, bloomDay, m, k);
        if (possible_to_make_bouquets == true)
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
    int m, k;
    cin >> m >> k;
    cout << minDays(arr, m, k) << endl;
}