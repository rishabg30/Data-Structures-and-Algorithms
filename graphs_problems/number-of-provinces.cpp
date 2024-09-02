#include <bits/stdc++.h>
using namespace std;
void dfs_algorithm(int startNode, vector<int> adj[], vector<int> &visited)
{
    visited[startNode] = 1;

    // Traverse the neighbours if still unvisited
    for (int i = 0; i < adj[startNode].size(); i++)
    {
        if (visited[adj[startNode][i]] == 0)
        {
            dfs_algorithm(adj[startNode][i], adj, visited);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> graph[n];

    // Convert matrix to adjacency list
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int count_provinces = 0;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs_algorithm(i, graph, visited);
            count_provinces++;
        }
    }
    return count_provinces;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Usually TC will be O(V + 2E) but we have converted matrix to list which takes O(N * N) in this case
    Time complexity: O(N * N)
    Space complexity: O(N)
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
    cout << findCircleNum(arr) << endl;
}