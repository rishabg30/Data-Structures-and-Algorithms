#include <bits/stdc++.h>
using namespace std;
class twoStacks
{
public:
    int *arr;
    int start_ptr;
    int end_ptr = 0;
    int size;
    twoStacks(int n = 100)
    {
        arr = new int[n];
        start_ptr = -1,
        end_ptr = n;
        size = n;
    }
    // Function to push an integer into the stack1.
    void push1(int x)
    {
        start_ptr++;
        if (start_ptr == end_ptr)
        {
            return;
        }
        else
        {
            arr[start_ptr] = x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        end_ptr--;
        if (start_ptr == end_ptr)
        {
            return;
        }
        else
        {
            arr[end_ptr] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (start_ptr == -1)
        {
            return -1;
        }
        int x = arr[start_ptr];
        start_ptr--;
        return x;
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (end_ptr == size)
        {
            return -1;
        }
        int x = arr[end_ptr];
        end_ptr++;
        return x;
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