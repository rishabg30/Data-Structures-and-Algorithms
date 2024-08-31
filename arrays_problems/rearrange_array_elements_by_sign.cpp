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
vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    int first_ptr_index = 0, second_ptr_index = 1;
    vector<int> ans(n);

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans[first_ptr_index] = nums[i];
            first_ptr_index += 2;
        }
        else
        {
            ans[second_ptr_index] = nums[i];
            second_ptr_index += 2;
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
    vector<int> ans = rearrangeArray(arr);
    printArray_1D(ans);
}