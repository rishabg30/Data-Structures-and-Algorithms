#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<long long> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
/* M-1 - TLE*/

/*
long long int find_negative_number(queue<long long int> q)
{
    long long int ans = 1e9;
    while (q.size() != 0)
    {
        if (q.front() < 0 && ans == 1e9)
        {
            ans = q.front();
            break;
        }
        else
        {
            q.pop();
        }
    }
    if (ans == 1e9)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}
vector<long long> printFirstNegativeInteger(long long int arr[], long long int n,
                                            long long int k)
{
    vector<long long> ans;
    queue<long long int> q;
    for (int i = 0; i < n; i++)
    {
        while (q.size() >= k)
        {
            long long int x = find_negative_number(q);
            ans.push_back(x);
            q.pop();
        }
        q.push(arr[i]);
    }
    while (q.size() > 0)
    {
        if (q.front() < 0)
        {
            ans.push_back(q.front());
            return ans;
        }
        else
        {
            q.pop();
        }
    }
    ans.push_back(0);
    return ans;
}
*/

/* M-2 */
long long int find_negative_number(int i, int k, queue<pair<long long int, long long int>> &q)
{
    long long int curr_top_element_index = q.front().first;
    long long int curr_top_element = q.front().second;

    // Checking if this element should be popped or it can be a part of future window
    if (i - curr_top_element_index + 1 >= k)
    {
        q.pop();
    }
    return curr_top_element;
}
vector<long long> printFirstNegativeInteger(long long int arr[], long long int n,
                                            long long int k)
{
    /* In this approach we will only store negative elements in queue. */
    vector<long long> ans;
    // will store {index, element}
    queue<pair<long long int, long long int>> q;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            q.push({i, arr[i]});
        }
        if (i >= k - 1)
        {
            if (q.size() != 0)
            {
                long long int x = find_negative_number(i, k, q);
                ans.push_back(x);
            }
            else
            {
                ans.push_back(0);
            }
        }
    }
    return ans;
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
    long long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int k;
    cin >> k;
    vector<long long> ans = printFirstNegativeInteger(arr, n, k);
    printArray_1D(ans);
}