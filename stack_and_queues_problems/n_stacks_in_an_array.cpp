#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int index;
    ListNode *next;
    ListNode(int x)
    {
        index = x;
        next = NULL;
    }
};
class NStack
{
public:
    int *arr; // original data
    /*
    top element index of particular stack. we created this double pointer because
    int *arr=new int[]; itself is a pointer pointing to integer type value stored in array.
    To point this we need a double pointer.
    */
    ListNode **top;
    stack<int> st; // to keep track of empty indexes

    // N -> number of stacks, S -> size of array
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new ListNode *[N];

        // Initialized NULL to every linkedlist array
        for (int i = 0; i < N; i++)
        {
            top[i] = NULL;
        }
        // Pushed indexes available right now
        for (int i = 0; i < S; i++)
        {
            st.push(i);
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Base Condition : if stack is empty, means no index left -> array full
        if (st.size() == 0)
        {
            return false;
        }
        // Storing value in original array
        arr[st.top()] = x;
        ListNode *temp = new ListNode(st.top());

        // Pointing to upwards direction
        temp->next = top[m - 1];
        top[m - 1] = temp;
        st.pop();
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Base Condition : if linkedlist array from which we have to pop is empty
        if (top[m - 1] == NULL)
        {
            return false;
        }
        // After popping, this index becomes empty, push it inside stack
        int element = arr[top[m - 1]->index];
        st.push(top[m - 1]->index);

        // Remove connection
        top[m - 1] = top[m - 1]->next;
        return element;
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
    Space complexity: O(N + S)
    */
}