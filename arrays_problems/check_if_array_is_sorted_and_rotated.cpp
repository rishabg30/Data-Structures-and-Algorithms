#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count++;
        }
    }
    if (nums[0] < nums[nums.size() - 1])
    {
        count++;
    }
    return (count <= 1) ? true : false;
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
    cout << check(arr) << endl;
}