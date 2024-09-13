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
/* With extra visited array and ds array which is keeping track of array elements */

/*
void permutations_function(int n, vector<int> &nums, vector<int> &ds, vector<int> &visited,
                           vector<vector<int>> &ans)
{
    // Base Condition
    if (ds.size() == n)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // If this element is not visited, then only take it
        if (visited[i] == 0)
        {
            visited[i] = 1;
            ds.push_back(nums[i]);
            permutations_function(n, nums, ds, visited, ans);

            // Not pop this element out and make visited[i] == 0 again for other permutations
            visited[i] = 0;
            ds.pop_back();
        }
    }
}
*/

/*Without any extra space*/
void permutations_function(int index, int n, vector<int> &nums, vector<vector<int>> &ans)
{

    // Base Condition
    if (index == n)
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        permutations_function(index + 1, n, nums, ans);

        // Again swap nums[i] with nums[index] for other permutations
        swap(nums[i], nums[index]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> visited(n, 0);
    // permutations_function(n, nums, ds, visited, ans);
    permutations_function(0, n, nums, ans);
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N! * N = N!)
    Space complexity: O(N ^ 2)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans = permute(arr);
    printArray_2D(ans);
}