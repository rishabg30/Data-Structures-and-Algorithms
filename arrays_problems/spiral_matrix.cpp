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
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    vector<int> ans;

    int dir = 0;
    while (true)
    {
        if (dir == 0)
        {
            // top row
            int i = left, j = right;
            while (i <= j)
            {
                ans.push_back(matrix[top][i]);
                i++;
            }
            top++;
            dir++;
        }
        else if (dir == 1)
        {
            // right column
            int i = top, j = bottom;
            while (i <= j)
            {
                ans.push_back(matrix[i][right]);
                i++;
            }
            right--;
            dir++;
        }
        else if (dir == 2)
        {
            // bottom row
            int i = right, j = left;
            while (i >= j)
            {
                ans.push_back(matrix[bottom][i]);
                i--;
            }
            bottom--;
            dir++;
        }
        else if (dir == 3)
        {
            // left column
            int i = bottom, j = top;
            while (i >= j)
            {
                ans.push_back(matrix[i][left]);
                i--;
            }
            left++;
            dir++;
        }
        dir = dir % 4;
        if (ans.size() == n * m)
        {
            break;
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
    Time complexity: O(N * M)
    Space complexity: O(N * M)
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
    vector<int> ans = spiralOrder(arr);
    printArray_1D(ans);
}