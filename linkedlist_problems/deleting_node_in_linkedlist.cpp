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
ListNode *deleteAtStart(ListNode *head, int pos)
{
    return head->next;
}
ListNode *deleteAtEnd(ListNode *head, int pos)
{
    ListNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
ListNode *deleteInBetween(ListNode *head, int pos)
{
    int count = 0;
    ListNode *temp = head;
    while (count < (pos - 1))
    {
        count++;
        temp = temp->next;
    }
    ListNode *next_element = temp->next->next;
    temp->next = next_element;
    return head;
}
ListNode *deleteNode(ListNode *head, int pos)
{
    pos--; // to make it 0 based indexing
    if (head == NULL)
    {
        return head;
    }
    int sizeOfLL = lengthLL(head);
    // If to be deleted at start of linkedlist
    if (pos == 0)
    {
        return deleteAtStart(head, pos);
    }
    // If to be deleted at end of linkedlist
    else if (pos == lengthLL(head) - 1)
    {
        return deleteAtEnd(head, pos);
    }
    // If to be deleted is in between (start, end)
    else
    {
        return deleteInBetween(head, pos);
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

    int pos;
    cin >> pos;
    node1 = deleteNode(node1, pos);
    printLL(node1);
}