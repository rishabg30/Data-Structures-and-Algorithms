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
void merge(vector<int> &arr, int low, int mid, int high)
{
    int n = arr.size();
    vector<int> temp;

    // [low.....mid]
    // [mid+1...high]
    int leftptr = low, rightptr = mid + 1;
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

    // Transforming back to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    int n = arr.size();
    if (low == high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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
    mergeSort(arr, 0, n - 1);
    printArray_1D(arr);
}