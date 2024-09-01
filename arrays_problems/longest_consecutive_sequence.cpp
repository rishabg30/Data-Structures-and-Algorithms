#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    // Firstly put every element in set
    int n = nums.size(), count = 0, max_length = 0;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }

    for (int i = 0; i < n; i++)
    {
        /*
        If nums[i] - 1 element is already present in set, no need to do anything
        it should have been a part of sequence already
        */
        if (st.find(nums[i] - 1) != st.end())
        {
            continue;
        }
        else
        {
            /*
            It is the beginning of new sequence. Iterative [by incrementing 1] till
            we are getting elements in set
            */
            count = 1;
            while (true)
            {
                if (st.find(nums[i] + count) != st.end())
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
        max_length = max(count, max_length);
    }
    return max_length;
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
    cout << longestConsecutive(arr) << endl;
}