#include <bits/stdc++.h>
using namespace std;
void printArray_2D(vector<vector<int>> &arr)
{
    for (auto it : arr)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; i++)
    {
        ans[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            // if j == 0 [first element] || j == i [last element] we have to print 1
            if (j == 0 || j == i)
            {
                ans[i][j] = 1;
            }
            else
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
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
    Space complexity: O(N * N)
    */
    int numRows;
    cin >> numRows;
    vector<vector<int>> ans = generate(numRows);
    printArray_2D(ans);
}