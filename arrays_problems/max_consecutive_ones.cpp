#include <bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int curr_count = 0, max_ones = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            curr_count++;
        }
        else
        {
            curr_count = 0;
        }
        max_ones = max(max_ones, curr_count);
    }
    return max_ones;
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
    cout << findMaxConsecutiveOnes(arr) << endl;
}