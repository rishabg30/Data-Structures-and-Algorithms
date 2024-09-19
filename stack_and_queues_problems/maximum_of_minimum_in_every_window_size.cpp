#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

/* M-1
    Time complexity: O(N ^ 3)
    Space complexity: O(N)
*/
/*
vector<int> maxOfMin(int arr[], int n)
{
    vector<int> ans(n, 0);

    // Start Iterating for every window
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int num = INT_MAX;
            for (int k = j; k < j + i + 1; k++)
            {
                num = min(num, arr[k]);
            }
            ans[i] = max(ans[i], num);
        }
    }
    return ans;
}
*/

/* M-2
    Time complexity: O(N)
    Space complexity: O(N)
*/
vector<int> maxOfMin(int arr[], int n)
{
    vector<int> ans(n, 0);

    // Used to store index of {NSL} for every element
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        // Finding out NSL and NSR for every element
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            int index = st.top();
            st.pop();
            if (st.size() == 0)
            {
                int range = i; // Max window size
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
            else
            {
                int range = i - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }
        st.push(i);
    }
    while (st.size() != 0)
    {
        int index = st.top();
        st.pop();
        if (st.size() == 0)
        {
            int range = n; // Max window size
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
        else
        {
            int range = n - st.top() - 1;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = maxOfMin(arr, n);
    printArray_1D(ans);
}