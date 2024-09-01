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
void dfs_algorithm(int startNode, int V, vector<int> adj[], vector<int> &visited,
                   vector<int> &ans)
{
    visited[startNode] = 1;
    ans.push_back(startNode);

    // Traverse the neighbours if unvisited
    for (int i = 0; i < adj[startNode].size(); i++)
    {
        if (visited[adj[startNode][i]] == 0)
        {
            // Call the dfs() algorithm for it's neighbour
            dfs_algorithm(adj[startNode][i], V, adj, visited, ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            dfs_algorithm(i, V, adj, visited, ans);
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
    Time complexity: O(V + 2E)
    Space complexity: O(V)
    */
    int ver, edg;
    cin >> ver >> edg;
    vector<int> adj[ver];
    for (int i = 0; i < edg; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dfs_ans = dfsOfGraph(ver, adj);
    printArray_1D(dfs_ans);
}