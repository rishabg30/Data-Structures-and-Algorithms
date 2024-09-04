#include <bits/stdc++.h>
using namespace std;
bool checkfn(int capacity, vector<int> &weights, int days)
{
    int n = weights.size(), curr_capacity = 0;
    for (int i = 0; i < n;)
    {
        if (curr_capacity + weights[i] > capacity)
        {
            curr_capacity = 0;
            days--;
        }
        else
        {
            curr_capacity += weights[i];
            i++;
        }
        if (days == 0)
        {
            return false;
        }
    }
    return true;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    // Defining the search space
    int low = 1, high = 0, ans = -1;
    for (int i = 0; i < n; i++)
    {
        high += weights[i];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool canShip = checkfn(mid, weights, days);
        if (canShip == true)
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
    int days;
    cin >> days;
    cout << shipWithinDays(arr, days) << endl;
}