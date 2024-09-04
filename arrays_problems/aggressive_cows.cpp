#include <bits/stdc++.h>
using namespace std;
bool checkfn(int distance_cap, vector<int> &stalls, int k)
{
    int n = stalls.size();
    // For maximum distance to acheive we can place one cow at the stall[0]
    k--;
    int initial_cow_position = stalls[0];
    for (int i = 1; i < n; i++)
    {
        int curr_distance = stalls[i] - initial_cow_position;
        if (curr_distance >= distance_cap)
        {
            initial_cow_position = stalls[i];
            k--; // Reduce the count of cow by 1 as it's placed here
        }
        if (k == 0)
        {
            return true;
        }
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls)
{
    // Defining the search space
    sort(stalls.begin(), stalls.end());
    int low = 0, high = *max_element(stalls.begin(), stalls.end());
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool canPlace = checkfn(mid, stalls, k);
        if (canPlace == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
    cout << solve(n, k, arr) << endl;
}