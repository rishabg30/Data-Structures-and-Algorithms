#include <bits/stdc++.h>
using namespace std;
// We will use circular array to implement deque
class Deque
{
    int *arr;
    int front, rear, size;

public:
    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool isFull()
    {
        if ((rear + 1) % size == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push_front(int x)
    {
        // if deque is empty
        if (isEmpty() == true)
        {
            cout << "Pushed front element: " << x << endl;
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // if deque is full
        else if (isFull() == true)
        {
            cout << "deque is full !" << endl;
            return;
        }
        // element can be pushed
        else
        {
            cout << "Pushed front element: " << x << endl;
            front = (front - 1 + size) % size;
            arr[front] = x;
            return;
        }
    }
    void push_back(int x)
    {
        // if deque is empty
        if (isEmpty() == true)
        {
            cout << "Pushed back element: " << x << endl;
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // if deque is full
        else if (isFull() == true)
        {
            cout << "deque is full !" << endl;
            return;
        }
        // element can be pushed
        else
        {
            cout << "Pushed back element: " << x << endl;
            rear = (rear + 1 + size) % size;
            arr[rear] = x;
            return;
        }
    }
    void pop_front()
    {
        // if deque is empty
        if (isEmpty() == true)
        {
            cout << "deque is empty !" << endl;
            return;
        }
        // deque is not empty
        else
        {
            // if only 1 element is present in deque
            if (front == rear)
            {
                front = rear = -1;
            }
            // if more than 1 element is present in deque
            else
            {
                front = (front + 1 + size) % size;
            }
        }
    }
    void pop_back()
    {
        // if deque is empty
        if (isEmpty() == true)
        {
            cout << "deque is empty !" << endl;
            return;
        }
        // deque is not empty
        else
        {
            // if only 1 element is present in deque
            if (front == rear)
            {
                front = rear = -1;
            }
            // if more than 1 element is present in deque
            else
            {
                rear = (rear - 1 + size) % size;
            }
        }
    }
    // function to give front element of deque
    int start()
    {
        // if deque is empty
        if (isEmpty() == true)
        {
            cout << "deque is empty !" << endl;
            return -1;
        }
        // deque is not empty
        else
        {
            return arr[front];
        }
    }
    // function to give last element of deque
    int end()
    {
        // if deque is empty
        if (isEmpty() == true)
        {
            cout << "deque is empty !" << endl;
            return -1;
        }
        // deque is not empty
        else
        {
            return arr[rear];
        }
    }
};
signed
main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(1)
    Space complexity: O(N)
    */

    Deque dq1(5);
    dq1.push_back(10);
    dq1.push_back(20);
    dq1.push_front(100);
    cout << dq1.start() << endl;
    cout << dq1.end() << endl;
    dq1.pop_front();
    cout << dq1.start() << endl;
}