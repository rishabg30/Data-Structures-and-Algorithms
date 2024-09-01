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
vector<int> getFloorAndCeil(int x, vector<int> &arr)
{
    int n = arr.size(), low = 0, high = n - 1;
    int floor_value = 0, ceil_value = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ceil_value = mid;
            high = mid - 1;
        }
        else
        {
            floor_value = mid;
            low = mid + 1;
        }
    }
    return {floor_value, ceil_value};
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
    int x;
    cin >> x;
    vector<int> ans = getFloorAndCeil(x, arr);
    printArray_1D(ans);
}