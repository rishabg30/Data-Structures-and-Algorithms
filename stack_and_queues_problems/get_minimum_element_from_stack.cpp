#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int minElement;
    stack<int> st;

public:
    /*returns min element from stack*/
    int getMin()
    {
        if (st.size() == 0)
        {
            return -1;
        }
        else
        {
            return st.top() % 101;
        }
    }

    /*returns poped element from stack*/
    int pop()
    {
        if (st.size() == 0)
        {
            return -1;
        }
        int element = st.top() / 101;
        st.pop();
        return element;
    }

    /*push element x into the stack*/
    void push(int x)
    {
        // If stack is empty
        if (st.size() == 0)
        {
            // Here we have stored two numbers in one number
            /*
            Lets say we had current number as 5 and min element as 2 we need
            to store both these values in same number.
            We are also given that 1<=num<=100, therefore generated number = 5 * 101 + 2 = 507
            To extract numbers back current number = 507 / 101 = 5, min element = 507 % 101 = 2
            */
            st.push(x * 101 + x);
        }
        else
        {
            st.push(x * 101 + min(x, st.top() % 101));
        }
    }
};
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
}