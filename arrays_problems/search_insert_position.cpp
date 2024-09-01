#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> &arr, int target)
{
    int n = arr.size(), low = 0, high = n - 1;
    int ceil_value = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            ceil_value = mid;
            high = mid - 1;
        }
    }
    return (ceil_value == -1) ? arr.size() : ceil_value;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O()
    Space complexity: O()
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << searchInsert(arr, target) << endl;
}