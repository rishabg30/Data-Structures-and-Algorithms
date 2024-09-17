#include <bits/stdc++.h>
using namespace std;
int permutations_count(vector<int> &arr, int target, string psf)
{
    int n = arr.size();
    // Base Condition
    if (target == 0)
    {
        cout << psf << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (target - arr[i] >= 0)
        {
            count += permutations_count(arr, target - arr[i], psf + to_string(arr[i]));
        }
    }
    return count;
}
int permutations_infinite_coin_supply(vector<int> &arr, int target)
{
    int countPermutation = permutations_count(arr, target, "");
    return countPermutation;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time Complexity: O(n^T), where n is the number of elements in arr and T is the target value.
    Space Complexity: O(T), primarily due to the recursion stack depth and the length of the permutation string.
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
    cout << permutations_infinite_coin_supply(arr, target) << endl;
}