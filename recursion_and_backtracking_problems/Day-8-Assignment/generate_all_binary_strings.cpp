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
void generate_binaryStrings_function(int startIdx, int num, string temp, vector<string> &ans)
{
    // Because while calling recursion we already have added one character
    if (startIdx == num - 1)
    {
        ans.push_back(temp);
        return;
    }
    // Conditions for taking '0'
    generate_binaryStrings_function(startIdx + 1, num, temp + "0", ans);
    // Conditions for taking '1'
    // Adding 1 only if previous element is not 1
    if (temp[startIdx] != '1')
    {
        generate_binaryStrings_function(startIdx + 1, num, temp + "1", ans);
    }
}
vector<string> generateBinaryStrings(int num)
{
    vector<string> ans;
    generate_binaryStrings_function(0, num, "0", ans);
    generate_binaryStrings_function(0, num, "1", ans);
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2^N)
    Space complexity: O(N)
    */
    int num;
    cin >> num;
    vector<string> ans = generateBinaryStrings(num);
    printArray_1D(ans);
}