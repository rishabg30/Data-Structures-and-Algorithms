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
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;

    // Step1: Sort the vector
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int left_ptr = j + 1, right_ptr = n - 1;
            while (left_ptr < right_ptr)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[left_ptr];
                sum += nums[right_ptr];
                if (sum < target)
                {
                    left_ptr++;
                }
                else if (sum > target)
                {
                    right_ptr--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[left_ptr], nums[right_ptr]});
                    left_ptr++;
                    right_ptr--;
                    while (left_ptr < right_ptr && nums[left_ptr] == nums[left_ptr - 1])
                    {
                        left_ptr++;
                    }
                    while (left_ptr < right_ptr && nums[right_ptr] == nums[right_ptr + 1])
                    {
                        right_ptr--;
                    }
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
    Time complexity: O(N^3)
    Space complexity: O(N^2)
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
    vector<vector<int>> ans = fourSum(arr, target);
    printArray_2D(ans);
}