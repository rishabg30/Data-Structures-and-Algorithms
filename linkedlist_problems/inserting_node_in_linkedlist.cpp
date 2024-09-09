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
void printLL(ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    ListNode *temp = node;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int lengthLL(ListNode *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
ListNode *insertAtStart(ListNode *head, int pos, int x)
{
    if (pos == 1)
    {
        ListNode *newNode = new ListNode(x);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
ListNode *insertAtEnd(ListNode *head, int pos, int x)
{
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new ListNode(x);
    return head;
}
ListNode *insertInBetween(ListNode *head, int pos, int x)
{
    int count = 1;
    ListNode *temp = head;
    while (count < (pos - 1))
    {
        count++;
        temp = temp->next;
    }
    ListNode *next_element = temp->next;
    ListNode *new_element = new ListNode(x);
    new_element->next = next_element;
    temp->next = new_element;
    return head;
}
ListNode *insertElement(ListNode *head, int pos, int x)
{
    int sizeOfLL = lengthLL(head);
    if (head == NULL)
    {
        if (pos == 1 || pos == lengthLL(head) + 1)
        {
            head = new ListNode(x);
        }
        return head;
    }
    // If x to be added at start of linkedlist
    if (pos == 1)
    {
        return insertAtStart(head, pos, x);
    }
    // If x to be added at end of linkedlist
    else if (pos == lengthLL(head) + 1)
    {
        return insertAtEnd(head, pos, x);
    }
    // If element is in between (start, end)
    else
    {
        return insertInBetween(head, pos, x);
    }
    return head;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(1)
    */
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    int pos, x;
    cin >> pos >> x;
    node1 = insertElement(node1, pos, x);
    printLL(node1);
}