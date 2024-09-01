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
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> ans;
    queue<int> q;

    // Push src node inside queue at begin.
    q.push(0);
    visited[0] = 1;

    while (q.size() != 0)
    {
        int curr_node = q.front();
        q.pop();
        ans.push_back(curr_node);

        // Traverse the neighbours and if unvisited push into queue
        for (int i = 0; i < adj[curr_node].size(); i++)
        {
            if (visited[adj[curr_node][i]] == 0)
            {
                visited[adj[curr_node][i]] = 1;
                q.push(adj[curr_node][i]);
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
    vector<int> bfs_ans = bfsOfGraph(ver, adj);
    printArray_1D(bfs_ans);
}