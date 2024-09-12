#include <bits/stdc++.h>
using namespace std;
void print_function(int startIdx, vector<int> &arr)
{
    if (startIdx == arr.size())
    {
        return;
    }
    cout << arr[startIdx] << " ";
    print_function(startIdx + 1, arr);
}
void printArray(vector<int> &arr)
{
    int startIdx = 0;
    print_function(startIdx, arr);
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
    printArray(arr);
}