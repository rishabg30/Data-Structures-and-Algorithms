#include <bits/stdc++.h>
using namespace std;
void dfs_algorithm(int startRow, int startCol, vector<vector<char>> &grid, vector<vector<int>> &visited,
                   vector<vector<int>> &dirS)
{
    int n = grid.size(), m = grid[0].size();
    visited[startRow][startCol] = 1;
    // Traverse the eight surrounding neighbours if unvisited
    for (int d = 0; d < dirS.size(); d++)
    {
        int nrow = startRow + dirS[d][0];
        int ncol = startCol + dirS[d][1];

        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == '1')
        {
            dfs_algorithm(nrow, ncol, grid, visited, dirS);
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> dirS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int number_of_islands = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && grid[i][j] == '1')
            {
                dfs_algorithm(i, j, grid, visited, dirS);
                number_of_islands++;
            }
        }
    }
    return number_of_islands;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N ^ 2)
    Space complexity: O(N ^ 2)
    */

    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << numIslands(arr) << endl;
}