#include <bits/stdc++.h>
using namespace std;
bool checkfn(int pageCapacity, vector<int> &arr, int m)
{
    int n = arr.size(), curr_pages = 0, count_students = 1;
    for (int i = 0; i < n; i++)
    {
        if (curr_pages + arr[i] <= pageCapacity)
        {
            curr_pages += arr[i];
        }
        else
        {
            // Give the book to next children
            count_students++;
            curr_pages = arr[i];
        }
    }
    if (count_students > m)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        return -1;
    }
    //  Defining the search space
    int low = *max_element(arr.begin(), arr.end());
    int high = 0, ans = -1;
    for (int i = 0; i < n; i++)
    {
        high += arr[i];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool canAllocate = checkfn(mid, arr, m);
        if (canAllocate == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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
    Time complexity: O(NLogN)
    Space complexity: O(1)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    cout << findPages(arr, n, m) << endl;
}