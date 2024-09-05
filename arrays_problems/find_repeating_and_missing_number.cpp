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
vector<int> findTwoElement(vector<int> arr)
{
    int n = arr.size(), XOR = 0;
    // Step 1->Take XOR of all elements present in array
    for (int i = 0; i < n; i++)
    {
        XOR ^= arr[i];
    }
    // Step 2->Take XOR of numbers from 1->N
    for (int i = 1; i <= n; i++)
    {
        XOR ^= i;
    }
    // We get something like X ^ Y = A

    /* Step 3->
    Now find out the differentiating bit in A which will help
    segregate our two buckets
    */
    int temp = XOR, count = 0;
    while (temp != 0)
    {
        if ((temp & (1 << count)) != 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }

    /* Step 4-> Segregation into two buckets
    1st bucket - elements containing their bit as 0
    2nd bucket - elements containing their bit as 1
    */
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        int mask = (1 << count);
        if ((arr[i] & mask) != 0)
        {
            x ^= arr[i];
        }
        else
        {
            y ^= arr[i];
        }
    }
    // Similarly, do for numbers from 1->N
    for (int i = 1; i <= n; i++)
    {
        int mask = (1 << count);
        if ((i & mask) != 0)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }

    /* Step 5-> Now we got x and y which is our missing and
       repeating numbers. To find out which number is missing
       and repeating just iterate over the array
    */

    int repeat_number = 0, missing_number = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            repeat_number = x;
            break;
        }
    }
    if (repeat_number == 0)
    {
        repeat_number = y;
        missing_number = x;
    }
    else
    {
        missing_number = y;
    }
    return {repeat_number, missing_number};
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(N)
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = findTwoElement(arr);
    printArray_1D(ans);
}