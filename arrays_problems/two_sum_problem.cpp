#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    map<int, int> mp;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mp.insert(make_pair(nums[i], i));
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
    Time complexity: O(N)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vector<int> ans = twoSum(arr, target);
    printArray_1D(ans);
}