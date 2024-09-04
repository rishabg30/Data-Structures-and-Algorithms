#include <bits/stdc++.h>
using namespace std;
long long int merge(long long arr[], int low, int mid, int high)
{
    vector<long long> temp;
    // [low.....mid]
    // [mid+1...high]
    int leftptr = low, rightptr = mid + 1;
    long long int curr_count = 0;
    while (leftptr <= mid && rightptr <= high)
    {
        if (arr[leftptr] <= arr[rightptr])
        {
            temp.push_back(arr[leftptr]);
            leftptr++;
        }
        else
        {
            temp.push_back(arr[rightptr]);
            rightptr++;
            curr_count += (mid - leftptr + 1);
        }
    }
    while (leftptr <= mid)
    {
        temp.push_back(arr[leftptr]);
        leftptr++;
    }
    while (rightptr <= high)
    {
        temp.push_back(arr[rightptr]);
        rightptr++;
    }

    // Converting back to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return curr_count;
}
long long int mergeSort(long long arr[], int low, int high, int n)
{

    if (low == high)
    {
        return 0;
    }
    int mid = (low + (high - low) / 2);
    long long int count = 0;
    count += mergeSort(arr, low, mid, n);
    count += mergeSort(arr, mid + 1, high, n);
    count += merge(arr, low, mid, high);
    return count;
}
long long int inversionCount(long long arr[], int n)
{
    int low = 0, high = n - 1;
    return mergeSort(arr, low, high, n);
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
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << inversionCount(arr, n) << endl;
}