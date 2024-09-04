#include <bits/stdc++.h>
using namespace std;
bool checkfn(int capacity, vector<int> &boards, int k)
{

    int n = boards.size(), curr_capacity = 0;
    for (int i = 0; i < n;)
    {
        if (curr_capacity + boards[i] > capacity)
        {
            curr_capacity = 0;
            k--;
        }
        else
        {
            curr_capacity += boards[i];
            i++;
        }
        if (k == 0)
        {
            return false;
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    // Defining the search space
    int low = 0, high = 0, ans = -1;
    for (int i = 0; i < n; i++)
    {
        low = max(low, boards[i]);
        high += boards[i];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool canPaint = checkfn(mid, boards, k);
        if (canPaint == true)
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
    int k;
    cin >> k;
    cout << findLargestMinDistance(arr, k) << endl;
}