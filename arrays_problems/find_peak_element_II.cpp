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
int findIndex(vector<vector<int>> &matrix, int n, int m, int mid)
{
    int curr_max = -1, curr_idx = -1;
    // Traverse in mid column and find max_element
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][mid] > curr_max)
        {
            curr_max = matrix[i][mid];
            curr_idx = i;
        }
    }
    return curr_idx;
}
vector<int> findPeakGrid(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // Finding maxIndex in midColumn
        int maxRowIndex = findIndex(matrix, n, m, mid);
        // Checking if left element exists
        int left_element_of_mid = (mid - 1 >= 0) ? matrix[maxRowIndex][mid - 1] : -1;
        // Checking if right element exists
        int right_element_of_mid = (mid + 1 < m) ? matrix[maxRowIndex][mid + 1] : -1;

        /* If our matrix[maxRowIndex][mid] is greater than both left_element_of_mid and
        right_element_of_mid then it will be a peak element as we know it's the max element
        of that column, therefore no need to check for above and down elements.
        */
        if (matrix[maxRowIndex][mid] > left_element_of_mid && matrix[maxRowIndex][mid] > right_element_of_mid)
        {
            return {maxRowIndex, mid};
        }
        else if (matrix[maxRowIndex][mid] < left_element_of_mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N * LogM)
    Space complexity: O(1)
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
    vector<int> ans = findPeakGrid(arr);
    printArray_1D(ans);
}