#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int expected_sum = (n * (n + 1)) / 2;

    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += nums[i];
    }
    return expected_sum - curr_sum;
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
    cout << missingNumber(arr) << endl;
}