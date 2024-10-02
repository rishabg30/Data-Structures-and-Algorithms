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
void dfs_algorithm(int sourceRow, int sourceCol, vector<vector<int>> &image, int initalFilledColor, int color,
                   vector<vector<int>> &dirS, vector<vector<int>> &ans)
{
    int n = image.size(), m = image[0].size();
    // Color the inital pixel with new color
    ans[sourceRow][sourceCol] = color;

    // Moving 4-directional neighbours and if they have same color applying dfs() algorithm
    for (int d = 0; d < dirS.size(); d++)
    {
        int nrow = sourceRow + dirS[d][0];
        int ncol = sourceCol + dirS[d][1];

        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == initalFilledColor && ans[nrow][ncol] != color)
        {
            dfs_algorithm(nrow, ncol, image, initalFilledColor, color, dirS, ans);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size(), m = image[0].size();
    vector<vector<int>> ans = image;
    int initalFilledColor = image[sr][sc];
    vector<vector<int>> dirS = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    // Applying dfs_algorithm for that pixel point
    dfs_algorithm(sr, sc, image, initalFilledColor, color, dirS, ans);
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
    int sr, sc, color;
    cin >> sr >> sc >> color;
    vector<vector<int>> ans = floodFill(arr, sr, sc, color);
    printArray_2D(ans);
}