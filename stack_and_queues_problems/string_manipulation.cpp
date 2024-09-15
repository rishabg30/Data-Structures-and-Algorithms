#include <bits/stdc++.h>
using namespace std;
int removeConsecutiveSame(vector<string> &arr)
{
    int n = arr.size();
    stack<string> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            st.push(arr[i]);
            continue;
        }
        else
        {
            if (st.top() == arr[i])
            {
                st.pop();
            }
            else
            {
                st.push(arr[i]);
            }
        }
    }
    return st.size();
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
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << removeConsecutiveSame(arr) << endl;
}