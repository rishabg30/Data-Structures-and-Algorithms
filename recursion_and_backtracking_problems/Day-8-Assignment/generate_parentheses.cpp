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
void generateParenthesis_function(int n, int leftParenthesis, int rightParenthesis,
                                  string &temp, vector<string> &ans)
{
    /*
    Base Condition : we know in every valid parenthesis of length n, there are n leftParenthesis
    and n rightParenthesis
    */
    if (leftParenthesis == n && rightParenthesis == n)
    {
        ans.push_back(temp);
        return;
    }
    // Conditions for leftParenthesis
    if (leftParenthesis < n)
    {
        // Adding leftParenthesis
        temp.push_back('(');
        generateParenthesis_function(n, leftParenthesis + 1, rightParenthesis, temp, ans);
        // Not Adding leftParenthesis
        temp.pop_back();
    }
    // Conditions for rightParenthesis
    if (rightParenthesis < n && rightParenthesis < leftParenthesis)
    {
        // Adding rightParenthesis
        temp.push_back(')');
        generateParenthesis_function(n, leftParenthesis, rightParenthesis + 1, temp, ans);
        // Not Adding rightParenthesis
        temp.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    int leftParenthesis = 0, rightParenthesis = 0;
    string temp;
    vector<string> ans;
    generateParenthesis_function(n, leftParenthesis, rightParenthesis, temp, ans);
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2 ^N)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis(n);
    printArray_1D(ans);
}