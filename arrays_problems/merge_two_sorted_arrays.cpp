#include <bits/stdc++.h>
using namespace std;

/* The tricky part is to sort it in O(1) space complexity
    Normal version
    Time complexity: O(NLogN)
    Space complexity: O(1)
*/
void swapIfGreater(vector<int> &arr1, int index1, vector<int> &arr2, int index2)
{
    if (arr1[index1] > arr2[index2])
    {
        swap(arr1[index1], arr2[index2]);
    }
}
void merge(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    // Defining gap
    int gap = (n + m) / 2;

    while (gap > 0)
    {
        int leftptr = 0, rightptr = leftptr + gap;
        while (rightptr < (n + m))
        {
            // Case1 -> when leftptr belongs in arr1 and rightptr belongs in arr2
            if (leftptr < n && rightptr >= n)
            {
                swapIfGreater(arr1, leftptr, arr2, rightptr - n);
            }
            // Case2 -> when both leftptr and rightptr belongs in arr2
            else if (leftptr >= n)
            {
                swapIfGreater(arr1, leftptr - n, arr2, rightptr - n);
            }
            // Case3-> when both leftptr and rightptr belongs in arr1
            else
            {
                swapIfGreater(arr1, leftptr, arr2, rightptr);
            }
            leftptr++;
            rightptr++;
        }
        if (gap == 1)
        {
            break;
        }
        gap = (gap / 2) + (gap % 2);
    }
}

// LeetCode Version
void printArray_1D(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

/*
LeetCode version
Time complexity: O(N)
Space complexity: O(1)

void merge(vector<int> &arr1, int n, vector<int> &arr2, int m)
{

    if (m == 0)
    {
        return;
    }
    int end_index = arr1.size() - 1;
    while (n > 0 && m > 0)
    {
        if (arr2[m - 1] >= arr1[n - 1])
        {
            arr1[end_index] = arr2[m - 1];
            m--;
        }
        else
        {
            arr1[end_index] = arr1[n - 1];
            n--;
        }
        end_index--;
    }
    while (m > 0)
    {
        arr1[end_index] = arr2[m - 1];
        m--;
        end_index--;
    }
}
*/
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    merge(arr1, n, arr2, m);
    printArray_1D(arr1);
    printArray_1D(arr2);
}