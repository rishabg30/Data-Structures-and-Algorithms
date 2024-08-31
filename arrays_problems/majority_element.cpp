#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int majority_element = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            majority_element = nums[i];
        }
        if (nums[i] == majority_element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return majority_element;
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
    cout << majorityElement(arr) << endl;
}