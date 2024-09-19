#include <bits/stdc++.h>
using namespace std;
int largest_rectangle_formed(vector<int> &heights)
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
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int maxArea = 0;
    vector<int> heights(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
            {
                heights[j] = 0;
            }
            else
            {
                heights[j] += 1;
            }
        }
        maxArea = max(maxArea, largest_rectangle_formed(heights));
    }
    return maxArea;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N * M)
    Space complexity: O(N)
    */
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << maximalRectangle(arr) << endl;
}