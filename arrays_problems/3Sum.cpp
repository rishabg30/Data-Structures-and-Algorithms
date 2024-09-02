#include <bits/stdc++.h>
using namespace std;
void printArray_2D(vector<vector<int>> &arr)
{
    for (auto it : arr)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    // Step 1 sort the elements
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        // Check to not have duplicates
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            // If sum < 0 then increment j pointer
            if (sum < 0)
            {
                j++;
            }
            // If sum > 0 then decrement k pointer
            else if (sum > 0)
            {
                k--;
            }
            // We got the desired sum
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                // Check 2: to remove duplicates for j and k pointer
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
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
    Time complexity: O(N^2 + NLogN)
    Space complexity: O(N^2)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans = threeSum(arr);
    printArray_2D(ans);
}