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
void find_all_Paths(int src_row, int src_col, vector<vector<int>> &matrix, vector<vector<int>> &dirS,
                    vector<char> &dir, vector<vector<int>> &visited, vector<string> &ans, string psf)
{
    int n = matrix.size(), m = matrix[0].size();
    // Base Condition
    if (src_row == n - 1 && src_col == m - 1)
    {
        ans.push_back(psf);
        return;
    }

    visited[src_row][src_col] = 1;
    // Traverse it's neighbours
    for (int d = 0; d < dirS.size(); d++)
    {
        int nrow = src_row + dirS[d][0];
        int ncol = src_col + dirS[d][1];

        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
            visited[nrow][ncol] == 0 && matrix[nrow][ncol] == 1)
        {
            find_all_Paths(nrow, ncol, matrix, dirS, dir, visited, ans, psf + dir[d]);
        }
    }
    // Backtrack and unmark this path to unvisited
    visited[src_row][src_col] = 0;
}
vector<string> findPath(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    if (matrix[0][0] == 0 || matrix[n - 1][m - 1] == 0)
    {
        return {};
    }
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> dirS = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    vector<char> dir = {'D', 'L', 'R', 'U'};
    vector<string> ans;
    find_all_Paths(0, 0, matrix, dirS, dir, visited, ans, "");
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    At every block, person has 3 directions to move [1 will be already visited]
    and total number of blocks are N^2. Therefore TC: O(3^N^2)
    Time complexity: O(3^N^2)
    Space complexity: O(l * x)
    Here l = length of the path, x = number of paths.
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
    vector<string> ans = findPath(arr);
    printArray_1D(ans);
}