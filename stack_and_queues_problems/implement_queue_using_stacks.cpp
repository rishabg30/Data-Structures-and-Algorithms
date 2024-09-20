#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> st1; // Used for push operation
    stack<int> st2; // Used for pop operation
    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        // If our queue is empty, return -1;
        if (empty())
        {
            return -1;
        }
        else
        {
            // If stack 2 is not empty, simply pop out the element
            if (st2.size() != 0)
            {
                int element = st2.top();
                st2.pop();
                return element;
            }
            // If stack 2 is empty, fill stack 1 elements in stack 2
            else
            {
                while (st1.size() > 1)
                {
                    st2.push(st1.top());
                    st1.pop();
                }
                // Pop out the last element which is in stack 1
                int element = st1.top();
                st1.pop();
                return element;
            }
        }
    }

    int peek()
    {
        // If our queue is empty, return -1;
        if (empty())
        {
            return -1;
        }
        // If there are elements in stack 2, peek will be st.top();
        else if (st2.size() != 0)
        {
            return st2.top();
        }
        // If stack 2 is empty, fill stack 1 elements in stack 2
        else
        {
            while (st1.size() > 0)
            {
                st2.push(st1.top());
                st1.pop();
            }
            // peek element will be at st2.top()
            return st2.top();
        }
    }

    bool empty()
    {
        if (st1.size() == 0 && st2.size() == 0)
        {
            return true;
        }
        return false;
    }
};
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    For all operations, TC is amortized O(1)
    Time complexity: O(1)
    Space complexity: O(N)
    */
}