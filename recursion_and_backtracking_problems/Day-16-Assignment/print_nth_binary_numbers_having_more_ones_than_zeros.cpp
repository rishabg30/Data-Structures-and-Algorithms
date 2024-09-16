#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void NBit_formation(int n, vector<string> &ans, int countOnes, int countZeros, string psf)
{
    // Base Condition
    if (n == 0)
    {
        ans.push_back(psf);
        return;
    }
    //  Picking up 1
    NBit_formation(n - 1, ans, countOnes + 1, countZeros, psf + "1");

    // Picking up 0
    if (countOnes > countZeros)
    {
        NBit_formation(n - 1, ans, countOnes, countZeros + 1, psf + "0");
    }
}
vector<string> NBitBinary(int n)
{
    vector<string> ans;
    NBit_formation(n, ans, 0, 0, "");
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2 ^ N)
    Space complexity: O(2 ^ N)
    */
    int n;
    cin >> n;
    vector<string> ans = NBitBinary(n);
    printArray_1D(ans);
}