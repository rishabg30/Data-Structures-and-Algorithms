#include <bits/stdc++.h>
using namespace std;
bool isPossibleToColor(int node, int n, bool graph[101][101], int curr_color, vector<int> &color_tracker)
{
    // Traversing all it's neighbours
    for (int i = 0; i < n; i++)
    {
        if (i != node && graph[i][node] == 1 && color_tracker[i] == curr_color)
        {
            return false;
        }
    }
    return true;
}
bool coloring_graph_function(int startNode, int n, bool graph[101][101],
                             int max_colors, vector<int> &color_tracker)
{
    // Base Condition
    if (startNode == n)
    {
        return true;
    }
    for (int i = 1; i <= max_colors; i++)
    {
        if (isPossibleToColor(startNode, n, graph, i, color_tracker) == true)
        {
            color_tracker[startNode] = i;
            if (coloring_graph_function(startNode + 1, n, graph, max_colors, color_tracker) == true)
            {
                return true;
            }
            color_tracker[startNode] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int max_colors, int n)
{
    vector<int> color_tracker(n, 0);
    if (coloring_graph_function(0, n, graph, max_colors, color_tracker) == true)
    {
        return true;
    }
    return false;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N ^ max_colors)
    Space complexity: O(N)
    */
}