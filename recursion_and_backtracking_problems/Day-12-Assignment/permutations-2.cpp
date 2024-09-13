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
/* Using set data structure to find only unique permutations */
/*
void permuteUnique_function(int index, int n, vector<int> &nums, set<vector<int>> &st)
{
    // Base Condition
    if (index == n)
    {
        st.insert(nums);
        return;
    }
    for (int i = index; i < n; i++)
    {
        swap(nums[i], nums[index]);
        permuteUnique_function(index + 1, n, nums, st);
        swap(nums[i], nums[index]);
    }
}
*/

/* Using visited array as we are given that -10 <= nums[i] <= 10 */
void permuteUnique_function(int index, int n, vector<int> &nums, vector<vector<int>> &ans)
{
    // Base Condition
    if (index == n)
    {
        ans.push_back(nums);
        return;
    }
    vector<int> visited(21, 0);
    for (int i = index; i < n; i++)
    {
        if (visited[nums[i] + 10] == 0)
        {
            swap(nums[i], nums[index]);
            permuteUnique_function(index + 1, n, nums, ans);
            swap(nums[i], nums[index]);
            visited[nums[i] + 10] = 1;
        }
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    /*
    set<vector<int>> st;
    permuteUnique_function(0, n, nums, st);
    for (auto it : st)
    {
        ans.push_back(it);
    }
    */

    permuteUnique_function(0, n, nums, ans);
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N!)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans = permuteUnique(arr);
    printArray_2D(ans);
}