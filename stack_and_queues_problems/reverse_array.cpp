#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<char> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void reverseString(vector<char> &arr)
{
    int n = arr.size();
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        st.push(arr[i]);
    }
    while (st.size() != 0)
    {
        cout << st.top() << " ";
        st.pop();
    }
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
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverseString(arr);
}