#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    /* We will use BFS algorithm here because at time t,
    wherever there is a fresh orange, it becomes rotten [level-order] */

    vector<vector<int>> dirS = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    // keep a queue storing {{row,col},time}
    queue<pair<pair<int, int>, int>> q;
    int maxTime = 0;

    // Iterate in the grid and push all rotten oranges indices into the queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }
    // Apply BFS algorithm
    while (q.size() > 0)
    {
        int curr_row = q.front().first.first;
        int curr_col = q.front().first.second;
        int curr_time = q.front().second;
        q.pop();
        maxTime = max(maxTime, curr_time);

        // Traverse the neighbours if still left [fresh oranges present]
        for (int d = 0; d < dirS.size(); d++)
        {
            int nrow = curr_row + dirS[d][0];
            int ncol = curr_col + dirS[d][1];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, curr_time + 1});
                grid[nrow][ncol] = 2;
            }
        }
    }
    // Check if still fresh oranges are left
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return maxTime;
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
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << orangesRotting(grid) << endl;
}