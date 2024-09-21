#include <bits/stdc++.h>
using namespace std;
// To implement a Deque, we will use doubly linkedlist
class ListNode
{
public:
    int val;
    ListNode *next, *prev;
    ListNode(int val)
    {
        this->val = val;
        next = prev = NULL;
    }
};
class Deque
{
    ListNode *front, *rear;

public:
    Deque()
    {
        front = rear = NULL;
    }
    void push_front(int x)
    {
        cout << "Pushed front element: " << x << endl;
        // If Deque is empty
        if (front == NULL)
        {
            front = rear = new ListNode(x);
        }
        // Deque is not empty
        else
        {
            ListNode *temp = new ListNode(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            return;
        }
    }
    void push_back(int x)
    {
        cout << "Pushed back element: " << x << endl;
        // If Deque is empty
        if (front == NULL)
        {
            front = rear = new ListNode(x);
        }
        // Deque is not empty
        else
        {
            ListNode *temp = new ListNode(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            return;
        }
    }
    void pop_front()
    {
        // If Deque is empty
        if (front == NULL)
        {
            cout << "Deque is empty !" << endl;
            return;
        }
        // Deque is not empty
        else
        {
            ListNode *temp = front;
            front = front->next;
            delete temp;

            // if front exists after moving 1 step forward
            if (front)
            {
                front->prev = NULL;
            }
            // if front becomes NULL
            else
            {
                rear = NULL;
            }
        }
    }
    void pop_back()
    {
        // If Deque is empty
        if (front == NULL)
        {
            cout << "Deque is empty !" << endl;
            return;
        }
        // Deque is not empty
        else
        {
            ListNode *temp = rear;
            rear = rear->prev;
            delete temp;

            // if rear exists after moving 1 step back
            if (rear)
            {
                rear->next = NULL;
            }
            // if rear becomes NULL
            else
            {
                front = NULL;
            }
        }
    }
    // Function to print front element of Deque
    int start()
    {
        // If Deque is empty
        if (front == NULL)
        {
            cout << "Deque is empty !" << endl;
            return -1;
        }
        // Deque is not empty
        else
        {
            return front->val;
        }
    }
    // Function to print last element of Deque
    int end()
    {
        // If Deque is empty
        if (front == NULL)
        {
            cout << "Deque is empty !" << endl;
            return -1;
        }
        // Deque is not empty
        else
        {
            return rear->val;
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
    Time complexity: O(1)
    Space complexity: O(N)
    */
    Deque dq1;
    dq1.push_back(7);
    dq1.push_front(5);
    cout << dq1.start() << endl;
    dq1.pop_front();
    cout << dq1.start() << endl;
    cout << dq1.end() << endl;
}