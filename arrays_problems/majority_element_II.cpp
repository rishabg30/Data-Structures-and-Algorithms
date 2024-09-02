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
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    // Key observation: there will always be <=2 elements only appearing more than n/3 times
    int element1 = 0, element2 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == element1)
        {
            count1++;
        }
        else if (nums[i] == element2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            element1 = nums[i];
            count1++;
        }
        else if (count2 == 0)
        {
            element2 = nums[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // Check whether element 1 and element 2 we found has frequency >= n/3 or not
    int element1_freq = 0, element2_freq = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == element1)
        {
            element1_freq++;
        }
        else if (nums[i] == element2)
        {
            element2_freq++;
        }
    }

    if (element1_freq > n / 3)
    {
        ans.push_back(element1);
    }
    if (element2_freq > n / 3)
    {
        ans.push_back(element2);
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
    vector<int> ans = majorityElement(arr);
    printArray_1D(ans);
}