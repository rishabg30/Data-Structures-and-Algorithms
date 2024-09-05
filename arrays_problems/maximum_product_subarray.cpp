#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int prefix_product = 1, suffix_product = 1, maxProd = -1e9;
    for (int i = 0; i < n; i++)
    {
        if (prefix_product == 0)
        {
            prefix_product = 1;
        }
        if (suffix_product == 0)
        {
            suffix_product = 1;
        }
        prefix_product = prefix_product * nums[i];
        suffix_product = suffix_product * nums[n - i - 1];
        maxProd = max(maxProd, max(prefix_product, suffix_product));
    }
    return maxProd;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxProduct(arr) << endl;
}