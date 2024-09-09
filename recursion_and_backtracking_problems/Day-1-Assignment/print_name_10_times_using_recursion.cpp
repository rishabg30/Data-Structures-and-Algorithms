#include <bits/stdc++.h>
using namespace std;
void print_name(string name, int count)
{
    if (count == 0)
    {
        return;
    }
    cout << name << endl;
    print_name(name, count - 1);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(count)
    Space complexity: O(count)
    */
    string name;
    cin >> name;
    print_name(name, 10);
}