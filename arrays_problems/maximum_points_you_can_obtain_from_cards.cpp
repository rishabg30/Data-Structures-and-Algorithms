#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int maxPointsFromStart = 0;

    for (int i = 0; i < k; i++)
    {
        maxPointsFromStart += cardPoints[i];
    }

    /*
    Here we will slide our window from maxPointsFromStart -> maxPointsFromEnd and try to all
    possible scenario's and keep a track of maximumSum
    */
    int maxSum = maxPointsFromStart;

    int sptr = k - 1, eptr = 0;
    while (k--)
    {
        maxPointsFromStart -= cardPoints[sptr];         // removed the element
        maxPointsFromStart += cardPoints[n - eptr - 1]; // added the element
        maxSum = max(maxSum, maxPointsFromStart);
        sptr--;
        eptr++;
    }
    return maxSum;
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << maxScore(arr, k) << endl;
}