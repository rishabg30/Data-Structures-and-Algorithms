#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> &bills)
{
    int n = bills.size(), count_five_changes = 0, count_ten_changes = 0;
    for (int i = 0; i < n; i++)
    {
        // If customer is giving exact money, take it and move forward
        if (bills[i] == 5)
        {
            count_five_changes++;
        }
        // If customer pays 10$
        else if (bills[i] == 10)
        {
            // If we don't have a change, return false
            if (count_five_changes == 0)
            {
                return false;
            }
            count_ten_changes++;
            count_five_changes--;
        }
        // If customer pays 20$
        else
        {
            /* If we have change of 10$, first we will give that and then
            5$ change.
            */
            if (count_ten_changes > 0)
            {
                count_ten_changes--;
                if (count_five_changes > 0)
                {
                    count_five_changes--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                // We don't have a 10$ change
                if (count_five_changes >= 3)
                {
                    count_five_changes -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
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
    cout << lemonadeChange(arr) << endl;
}