#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    // Push all the competitiors for celebrity race into the stack
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        st.push(i);
    }
    // Start the competition until we are left with one competitior
    while (st.size() > 1)
    {
        int competitor_one = st.top();
        st.pop();
        int competitor_two = st.top();
        st.pop();

        // Check the relation between competitor_one and competitor_two

        /* Case 1: first competitor knows second competitor but second competitor does not know
        first competitor, therefore second competitor can be our celebrity */
        if (matrix[competitor_one][competitor_two] == 1 && matrix[competitor_two][competitor_one] == 0)
        {
            st.push(competitor_two);
        }
        /* Case 1: first competitor does not know second competitor but second competitor knows
        first competitor, therefore first competitor can be our celebrity */
        else if (matrix[competitor_one][competitor_two] == 0 && matrix[competitor_two][competitor_one] == 1)
        {
            st.push(competitor_one);
        }
        /* This includes case where both competitors knows each other or no one knows each other. In both
        cases both competitors can't be our celebrity */
        else
        {
            continue;
        }
    }
    if (st.size() == 0)
    {
        // No celebrity found
        return -1;
    }
    int possibleCelebrity = st.top();
    st.pop();

    // Confirm if this is the celebrity or not
    // Iterating to check this celebrity does not know anyone
    for (int i = 0; i < m; i++)
    {
        if (matrix[possibleCelebrity][i] == 1)
        {
            return -1;
        }
    }
    // Iterating to check if everyone knows this celebrity
    for (int i = 0; i < n; i++)
    {
        if (i == possibleCelebrity)
        {
            continue;
        }
        if (matrix[i][possibleCelebrity] == 0)
        {
            return -1;
        }
    }
    return possibleCelebrity;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << celebrity(arr) << endl;
}