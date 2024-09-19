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
class Queue
{
    ListNode *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
    void push(int x)
    {
        if (isEmpty())
        {
            cout << "Pushed element: " << x << endl;
            front = rear = new ListNode(x);
            return;
        }
        else
        {
            rear->next = new ListNode(x);
            rear = rear->next;
            cout << "Pushed element: " << x << endl;
        }
    }
    void pop()
    {
        if (isEmpty() == true)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        else
        {
            ListNode *temp = front;
            front = front->next;
            delete temp;
        }
    }
    int top()
    {
        if (isEmpty() == true)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else
        {
            return front->val;
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
    Time complexity: O()
    Space complexity: O()
    */
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    cout << q.top() << endl;
    cout << q.isEmpty() << endl;
    q.push(500);
    cout << q.top() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
}