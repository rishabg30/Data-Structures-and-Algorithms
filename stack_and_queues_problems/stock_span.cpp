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
vector<int> calculateSpan(int price[], int n)
{
    /* our stack will hold {price[i], count}
    count - denotes smaller consecutive days before this index
    */
    vector<int> ans(n);
    ans[0] = 1;
    stack<pair<int, int>> st;
    st.push(make_pair(price[0], 1));
    for (int i = 1; i < n; i++)
    {
        int count = 1;
        while (st.size() > 0 && price[i] >= st.top().first)
        {
            count += st.top().second;
            st.pop();
        }
        if (st.size() != 0)
        {
            ans[i] = count;
        }
        ans[i] = count;
        st.push(make_pair(price[i], count));
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
    vector<int> ans = calculateSpan(arr, n);
    printArray_1D(ans);
}