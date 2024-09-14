#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};
class Stack
{
private:
    ListNode *head;
    int size;

    /* Here we have not defined size of stack as it is going to be implemented
    by linkedlist which is dynamic in nature.
    */
public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    /* Here stack overflow condition is not required. */
    void push(int element)
    {
        ListNode *temp = new ListNode(element);
        temp->next = head;
        head = temp;
        size++;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        ListNode *temp = head;
        head = head->next;
        delete (temp);
        size--;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return head->val;
        }
    }

    int isSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if (head == NULL)
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
    Time complexity: Push() -> O(1), Pop() -> O(1), Top() -> O(1)
    Space complexity: O(N)
    */
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.isSize() << endl;
    st.push(100);
    cout << st.isEmpty() << endl;
}