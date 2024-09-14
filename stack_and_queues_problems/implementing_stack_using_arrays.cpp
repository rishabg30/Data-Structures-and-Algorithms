#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int *arr;
    int size;
    int index;

public:
    Stack(int size)
    {
        this->size = size;
        index = -1;
        arr = new int[size];
    }

    void push(int element)
    {
        // Stack overflow condition
        if (index == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        else
        {
            index++;
            arr[index] = element;
        }
    }

    void pop()
    {
        // Stack underflow condition
        if (index == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else
        {
            index--;
        }
    }

    int top()
    {
        if (index == size - 1)
        {
            cout << "Stack overflow" << endl;
            return -1;
        }
        else if (index == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[index];
        }
    }

    int isSize()
    {
        return index + 1;
    }

    bool isEmpty()
    {
        return (isSize() >= 1) ? false : true;
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

    Stack st(5);
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