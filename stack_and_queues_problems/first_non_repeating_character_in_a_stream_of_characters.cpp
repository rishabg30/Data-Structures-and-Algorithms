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
string finding_non_repeating_characters(string &str)
{
    queue<char> q;
    string new_str;
    vector<int> char_freq(26, 0);

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        // It means we have encountered this character first time, and as queue is empty it means this is the first non-repeating character
        if (q.size() == 0 && char_freq[ch - 'a'] == 0)
        {
            new_str += ch;
            q.push(ch);
        }
        // It means we have encountered another new non-repeating character but in queue as there are characters left, therefore they will be printed
        else if (ch != q.front() && char_freq[ch - 'a'] == 0)
        {
            new_str += q.front();
            q.push(ch);
        }
        else
        {
            while (q.size() > 0 && (char_freq[q.front() - 'a'] > 1 || ch == q.front()))
            {
                q.pop();
            }
            if (q.size() == 0)
            {
                new_str += '#';
            }
            else
            {
                new_str += q.front();
            }
        }
        char_freq[ch - 'a']++;
    }
    return new_str;
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
    string str;
    cin >> str;
    cout << finding_non_repeating_characters(str) << endl;
}