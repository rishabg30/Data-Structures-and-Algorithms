#include <bits/stdc++.h>
using namespace std;
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int n = tickets.size();
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        q.push({i, tickets[i]});
    }

    int count = 0;
    while (true)
    {
        pair<int, int> curr_person = q.front();
        q.pop();
        curr_person.second--;
        if (curr_person.second == 0)
        {
            count++;
            if (curr_person.first == k)
            {
                break;
            }
            continue;
        }
        else
        {
            count++;
            q.push({curr_person.first, curr_person.second});
        }
    }
    return count;
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
    int k;
    cin >> k;
    cout << timeRequiredToBuy(arr, k) << endl;
}