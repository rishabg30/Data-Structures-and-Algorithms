#include <bits/stdc++.h>
using namespace std;
int max_element_function(int startIdx, vector<int> &arr)
{
    if (startIdx == arr.size())
    {
        return -1;
    }
    int maxElement = max_element_function(startIdx + 1, arr);
    if (arr[startIdx] > maxElement)
    {
        maxElement = arr[startIdx];
    }
    return maxElement;
}
int max_element_array(vector<int> &arr)
{
    int startIdx = 0;
    return max_element_function(startIdx, arr);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: ON)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << max_element_array(arr) << endl;
}