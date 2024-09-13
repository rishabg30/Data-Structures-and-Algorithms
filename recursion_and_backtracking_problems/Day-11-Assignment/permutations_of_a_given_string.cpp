#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void find_permutation_function(int index, int n, string &str, vector<string> &ans)
{
    // Base Condition
    if (index == n)
    {
        ans.push_back(str);
        return;
    }
    for (int i = index; i < n; i++)
    {
        swap(str[i], str[index]);
        find_permutation_function(index + 1, n, str, ans);
        // Again swap to make it back to original order for other permutations
        swap(str[i], str[index]);
    }
}
vector<string> find_permutation(string str)
{
    int n = str.size();
    vector<string> ans;
    find_permutation_function(0, n, str, ans);
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N!)
    Space complexity: O(N)
    */
    string str;
    cin >> str;
    vector<string> ans = find_permutation(str);
    printArray_1D(ans);
}