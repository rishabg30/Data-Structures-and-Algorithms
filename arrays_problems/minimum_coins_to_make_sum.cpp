#include <bits/stdc++.h>
using namespace std;
/*
https://www.naukri.com/code360/problems/minimum-coins_982764?leftPanelTabValue=PROBLEM

Bob went to his favourite bakery to buy some pastries. After picking up his favourite pastries his total bill was P cents.
He lives in Berland where all the money is in the form of coins with
denominations {1, 2, 5, 10, 20, 50, 100, 500, 1000}.
Bob is not very good at maths and thinks fewer coins mean less money and he will
be happy if he gives minimum number of coins to the shopkeeper.
Help Bob to find the minimum number of coins that sums to P cents (assume that Bob has an
infinite number of coins of all denominations).
*/
vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int minCoins(int sum)
{
    int n = coins.size();
    sort(coins.begin(), coins.end(), greater<int>());

    int minCoinsRequired = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        // If sum becomes 0, then break the loop
        if (sum == 0)
        {
            break;
        }
        if (coins[i] > sum)
        {
            continue;
        }
        else
        {
            minCoinsRequired += (sum / coins[i]);
            sum = sum % coins[i];
        }
    }
    return minCoinsRequired;
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
    int sum;
    cin >> sum;
    cout << minCoins(sum) << endl;
}