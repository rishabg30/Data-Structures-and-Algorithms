#include <bits/stdc++.h>
using namespace std;
int merge(int low, int mid, int high, vector<int> &nums)
{
    // Counting inversions
    int j = mid + 1, count_reverse_pairs = 0;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > 2 * (long long)nums[j])
        {
            j++;
        }
        count_reverse_pairs += (j - (mid + 1));
    }

    vector<int> temp;
    int leftptr = low, rightptr = mid + 1;
    while (leftptr <= mid && rightptr <= high)
    {
        if (nums[leftptr] <= nums[rightptr])
        {
            temp.push_back(nums[leftptr]);
            leftptr++;
        }
        else
        {
            temp.push_back(nums[rightptr]);
            rightptr++;
        }
    }
    while (leftptr <= mid)
    {
        temp.push_back(nums[leftptr]);
        leftptr++;
    }
    while (rightptr <= high)
    {
        temp.push_back(nums[rightptr]);
        rightptr++;
    }
    // Storing back to original array
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
    return count_reverse_pairs;
}
int mergeSort(int low, int high, vector<int> &nums)
{
    if (low == high)
    {
        return 0;
    }
    int count = 0;
    int mid = (low + high) / 2;
    count += mergeSort(low, mid, nums);
    count += mergeSort(mid + 1, high, nums);
    count += merge(low, mid, high, nums);
    return count;
}
int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    return mergeSort(0, n - 1, nums);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(NLogN)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << reversePairs(arr) << endl;
}