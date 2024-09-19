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
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }
    int isSize()
    {
        return rear + 1;
    }
    void push(int x)
    {
        if (isEmpty() == true)
        {
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
            rear++;
            arr[rear] = x;
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
                front++;
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
    q.push(20);
    cout << q.top() << endl;
    cout << q.isSize() << endl;
    q.pop();
    cout << q.isEmpty() << endl;
}