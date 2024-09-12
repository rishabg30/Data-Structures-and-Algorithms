#include <bits/stdc++.h>
using namespace std;
int sum_function(int startIdx, vector<int> &arr)
{
    if (startIdx == arr.size())
    {
        return 0;
    }
    int total_sum = sum_function(startIdx + 1, arr);
    return arr[startIdx] + total_sum;
}
int sum_of_array(vector<int> &arr)
{
    int startIdx = 0;
    return sum_function(startIdx, arr);
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
    cout << sum_of_array(arr);
}