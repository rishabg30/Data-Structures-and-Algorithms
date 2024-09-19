#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int n)
    {
        arr = new int[n];
        size = n;
        // front will tell who is in the front of the queue and rear will point to last element in the queue
        front = rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
    bool isQueueFull()
    {
        if ((rear + 1) % size == front)
        {
            return true;
        }
        return false;
    }
    void push(int x)
    {
        if (isEmpty() == true)
        {
            cout << "Pushed: " << x << " into the queue" << endl;
            front = rear = 0;
            arr[0] = x;
            return;
        }
        else if (isQueueFull() == true)
        {
            cout << "Queue overflowed" << endl;
            return;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Pushed: " << x << " into the queue" << endl;
        }
    }
    void pop()
    {
        if (isEmpty() == true)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            // If queue has only one element
            if (front == rear)
            {
                front--;
                rear--;
            }
            else
            {
                front = (front + 1) % size;
            }
        }
    }
    int top()
    {
        if (isEmpty() == true)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
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

    Queue q(5);
    q.push(5);
    q.push(15);
    q.push(51);
    q.push(125);
    q.pop();
    q.push(512);
    q.push(38);
    q.push(100);
    cout << q.top() << endl;
    cout << q.isEmpty() << endl;
}