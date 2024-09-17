#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size(), ans = 0;
    int index = 0;

    // Stack will store {indexes of blocks}
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        // Find out NSE {rightside} for this block
        while (st.size() > 0 && heights[st.top()] > heights[i])
        {
            index = st.top();
            st.pop();
            if (st.size() > 0)
            {
                ans = max(ans, heights[index] * (i - st.top() - 1));
            }
            else
            {
                // if no previous smaller element found
                ans = max(ans, heights[index] * i);
            }
        }
        st.push(i);
    }
    while (st.size() != 0)
    {
        index = st.top();
        st.pop();
        if (st.size() > 0)
        {
            // here st.top().second will be storing pse
            ans = max(ans, heights[index] * (n - st.top() - 1));
        }
        else
        {
            // if no previous smaller element found
            ans = max(ans, heights[index] * n);
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << largestRectangleArea(arr) << endl;
}