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
vector<int> makeBeautiful(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans;

    // Push first element into stack
    st.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (st.size() == 0)
        {
            st.push(arr[i]);
            continue;
        }
        int curr_element_of_array = arr[i];
        int top_element_of_stack = st.top();
        if ((curr_element_of_array >= 0 && top_element_of_stack < 0) ||
            (curr_element_of_array < 0 && top_element_of_stack >= 0))
        {
            st.pop();
        }
        else
        {
            st.push(arr[i]);
        }
    }
    while (st.size() > 0)
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
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
    vector<int> ans = makeBeautiful(arr);
    printArray_1D(ans);
}