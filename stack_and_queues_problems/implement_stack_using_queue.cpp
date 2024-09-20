#include <bits/stdc++.h>
using namespace std;
class MyStack
{
public:
    // Here both queues are handling all operations. At one time either q1 will have elements or q2 will have elements.
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        // If both queues are empty, then push it in q1
        if (q1.size() == 0 && q2.size() == 0)
        {
            q1.push(x);
        }
        // otherwise push it in that queue where element is present
        else if (q1.size() != 0)
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }

    int pop()
    {
        // If both queues are empty, then return -1
        if (q1.size() == 0 && q2.size() == 0)
        {
            return -1;
        }
        // If q1 is empty, then last element of q2 has to be popped
        else if (q1.size() == 0)
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            // Now pop element from q2
            int element = q2.front();
            q2.pop();
            return element;
        }
        // If q2 is empty, then last element of q1 has to be popped
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            // Now pop element from q1
            int element = q1.front();
            q1.pop();
            return element;
        }
    }

    int top()
    {
        // If both queues are empty, then return -1
        if (q1.size() == 0 && q2.size() == 0)
        {
            return -1;
        }
        else if (q1.size() == 0)
        {
            return q2.back();
        }
        else
        {
            return q1.back();
        }
    }

    bool empty()
    {
        if (q1.size() == 0 && q2.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
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
    For all operations, TC is amortized O(1)
    Time complexity: O(1)
    Space complexity: O(N)
    */
}