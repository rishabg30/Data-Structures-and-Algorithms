#include <bits/stdc++.h>
using namespace std;
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    if (n == 1)
    {
        return 1;
    }
    vector<int> candies(n, 1); // Start with giving 1 candy to each child

    // From left -> right
    for (int i = 1; i < n; i++)
    {
        // Give 1 more candy then previous index element
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // From right ->left
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    int total_candies = accumulate(candies.begin(), candies.end(), 0);
    return total_candies;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2N)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << candy(arr) << endl;
}