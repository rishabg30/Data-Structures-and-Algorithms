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
vector<int> bracketNumbers(string str)
{
    int n = str.size(), count = 1;
    stack<pair<char, int>> st;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            st.push({str[i], count});
            ans.push_back(count);
            count++;
        }
        if (str[i] == ')')
        {
            pair<char, int> top_pair = st.top();
            ans.push_back(top_pair.second);
            st.pop();
        }
        else
        {
            continue;
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
    string str;
    cin >> str;
    vector<int> ans = bracketNumbers(str);
    printArray_1D(ans);
}