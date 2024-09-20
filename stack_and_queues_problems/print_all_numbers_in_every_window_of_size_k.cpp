#include <bits/stdc++.h>
using namespace std;
void print_queue(queue<int> q)
{
    while (q.size() != 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
void print_numbers_in_window_k(vector<int> &arr, int k)
{
    int n = arr.size();
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        while (q.size() >= k)
        {
            print_queue(q);
            q.pop();
        }
        q.push(arr[i]);
    }
    print_queue(q);
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
    print_numbers_in_window_k(arr, k);
}