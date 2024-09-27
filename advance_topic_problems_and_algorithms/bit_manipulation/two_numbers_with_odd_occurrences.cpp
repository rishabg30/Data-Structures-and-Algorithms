#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<long long int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
vector<long long int> twoOddNum(long long int arr[], long long int n)
{
    vector<long long int> ans;
    // Step 1: Take Xor of array elements
    int xor_of_elements = 0;
    for (int i = 0; i < n; i++)
    {
        xor_of_elements ^= arr[i];
    }

    // Step 2:Find the differentiating bit
    int count = 0, temp = xor_of_elements;
    while (temp != 0)
    {
        if (temp & 1)
        {
            break;
        }
        count++;
        temp = temp >> 1;
    }

    // Segregate numbers in two buckets according to their bit at count index
    long long int XOR1 = 0, XOR2 = 0;
    for (int i = 0; i < n; i++)
    {
        int mask = (1 << count);
        if (arr[i] & mask)
        {
            XOR1 ^= arr[i];
        }
        else
        {
            XOR2 ^= arr[i];
        }
    }
    ans.push_back(XOR1);
    ans.push_back(XOR2);
    sort(ans.begin(), ans.end(), greater<int>());
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
    int n = 8;
    long long int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
    vector<long long int> ans = twoOddNum(arr, n);
    printArray_1D(ans);
}