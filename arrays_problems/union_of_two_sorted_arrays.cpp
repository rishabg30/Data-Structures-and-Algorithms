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
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    int start_ptr1 = 0, start_ptr2 = 0;
    while (start_ptr1 < n && start_ptr2 < m)
    {
        while ((start_ptr1 + 1 < n) && (arr1[start_ptr1] == arr1[start_ptr1 + 1]))
        {
            start_ptr1++;
        }
        while ((start_ptr2 + 1 < m) && (arr2[start_ptr2] == arr2[start_ptr2 + 1]))
        {
            start_ptr2++;
        }
        if (arr1[start_ptr1] == arr2[start_ptr2])
        {
            ans.push_back(arr1[start_ptr1]);
            start_ptr1++;
            start_ptr2++;
        }
        else if (arr1[start_ptr1] < arr2[start_ptr2])
        {
            ans.push_back(arr1[start_ptr1]);
            start_ptr1++;
        }
        else
        {
            ans.push_back(arr2[start_ptr2]);
            start_ptr2++;
        }
    }

    while (start_ptr1 < n)
    {
        while ((start_ptr1 + 1 < n) && (arr1[start_ptr1] == arr1[start_ptr1 + 1]))
        {
            start_ptr1++;
        }
        ans.push_back(arr1[start_ptr1]);
        start_ptr1++;
    }
    while (start_ptr2 < m)
    {
        while ((start_ptr2 + 1 < m) && (arr2[start_ptr2] == arr2[start_ptr2 + 1]))
        {
            start_ptr2++;
        }
        ans.push_back(arr2[start_ptr2]);
        start_ptr2++;
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
    Time complexity: O(N)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<int> ans = findUnion(arr1, arr2, n, m);
    printArray_1D(ans);
}