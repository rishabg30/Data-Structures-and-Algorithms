#include <bits/stdc++.h>
using namespace std;
stack<int> _push(int arr[], int n)
{
    int minElement = 1e9;
    // your code here
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(min(minElement, arr[i]));
        minElement = min(minElement, arr[i]);
    }
    return st;
}

// Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> st)
{

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
}