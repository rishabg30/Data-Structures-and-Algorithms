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

void sortColors(vector<int> &nums)
{
    // Dutch National Flag Algorithm
    int n = nums.size();
    int first_ptr = 0, second_ptr = 0, third_ptr = n - 1;

    while (second_ptr <= third_ptr)
    {
        if (nums[second_ptr] == 0)
        {
            swap(nums[first_ptr], nums[second_ptr]);
            first_ptr++;
            second_ptr++;
        }
        else if (nums[second_ptr] == 1)
        {
            second_ptr++;
        }
        else if (nums[second_ptr] == 2)
        {
            swap(nums[second_ptr], nums[third_ptr]);
            third_ptr--;
        }
    }
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
    sortColors(arr);
    printArray_1D(arr);
}