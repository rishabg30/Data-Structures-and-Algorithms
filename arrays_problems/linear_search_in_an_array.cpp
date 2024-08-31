#include <bits/stdc++.h>
using namespace std;
int searchInSorted(int arr[], int N, int K)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == K)
        {
            return 1;
        }
    }
    return -1;
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
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int K;
    cin >> K;
    cout << searchInSorted(arr, N, K) << endl;
}