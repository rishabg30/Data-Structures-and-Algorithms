#include <bits/stdc++.h>
using namespace std;
int combinations_count(int index, vector<int> &arr, int target, string psf)
{
    int n = arr.size();
    // Base Condition
    if (target == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int count = 0;
    for (int i = index; i < n; i++)
    {
        if (target - arr[i] >= 0)
        {
            count += combinations_count(i + 1, arr, target - arr[i], psf + to_string(arr[i]));
        }
    }
    return count;
}
int combinations_finite_coin_supply(vector<int> &arr, int target)
{
    int countCombinations = combinations_count(0, arr, target, "");
    return countCombinations;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
     Time complexity: O(2 ^ N)
     Space complexity: O(N)
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
    cout << combinations_finite_coin_supply(arr, target) << endl;
}