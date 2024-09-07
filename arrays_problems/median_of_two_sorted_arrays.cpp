#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size(), n2 = arr2.size();
    if (n1 > n2)
    {
        /* As we always want to perform binary search on smaller array,
        therefore swaps it. */
        return findMedianSortedArrays(arr2, arr1);
    }
    int low = 0, high = n1;
    int total_elements = (n1 + n2);
    int elements_required_on_left = (n1 + n2 + 1) / 2;
    while (low <= high)
    {
        int mid_arr1 = (low + high) / 2;
        int mid_arr2 = elements_required_on_left - mid_arr1;
        int l1 = -1e9, l2 = -1e9, r1 = 1e9, r2 = 1e9;
        // Check if index exits, then only assign l1,l2,r1,r2
        if (mid_arr1 < n1)
        {
            r1 = arr1[mid_arr1];
        }
        if (mid_arr2 < n2)
        {
            r2 = arr2[mid_arr2];
        }
        if (mid_arr1 - 1 >= 0)
        {
            l1 = arr1[mid_arr1 - 1];
        }
        if (mid_arr2 - 1 >= 0)
        {
            l2 = arr2[mid_arr2 - 1];
        }
        // Possible solution
        if (l1 <= r2 && l2 <= r1)
        {
            // If total number of elements are odd
            if (total_elements & 1)
            {
                return max(l1, l2);
            }
            // there are even number of elements
            else
            {
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
        else if (l1 > r2)
        {
            high = mid_arr1 - 1;
        }
        else
        {
            low = mid_arr1 + 1;
        }
    }
    return 0;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(Log(min(n1,n2)))
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    cout << findMedianSortedArrays(arr1, arr2) << endl;
}