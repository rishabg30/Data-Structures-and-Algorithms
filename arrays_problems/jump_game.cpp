#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums)
{
    int n = nums.size(), max_jump_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > max_jump_index)
        {
            return false;
        }
        max_jump_index = max(max_jump_index, nums[i] + i);
    }
    return true;
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
    cout << canJump(arr) << endl;
}