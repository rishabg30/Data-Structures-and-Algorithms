#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count_of_missing_numbers_till_mid_index = arr[mid] - (mid + 1);
        if (count_of_missing_numbers_till_mid_index < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    /*
    Good observation: when binary search gets over our low pointer is 1 step ahead of
    our high pointer, therefore missing number = low + k;
    */
    return low + k;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(LogN)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << findKthPositive(arr, k) << endl;
}