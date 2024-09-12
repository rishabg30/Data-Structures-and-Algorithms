#include <bits/stdc++.h>
using namespace std;
int count_even_function(int startIdx, vector<int> &arr)
{
    if (startIdx == arr.size())
    {
        return 0;
    }
    int countEvenElements = count_even_function(startIdx + 1, arr);
    if (arr[startIdx] % 2 == 0)
    {
        countEvenElements++;
    }
    return countEvenElements;
}
int count_even_elements(vector<int> &arr)
{
    int startIdx = 0;
    return count_even_function(startIdx, arr);
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
    cout << count_even_elements(arr);
}