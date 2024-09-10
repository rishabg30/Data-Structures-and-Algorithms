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
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    int count = 1;
    ListNode *oddListStart = new ListNode(-1), *oddList = oddListStart;
    ListNode *evenListStart = new ListNode(-1), *evenList = evenListStart;
    ListNode *temp = head;

    while (temp != NULL)
    {
        if (count & 1)
        {
            oddList->next = temp;
            oddList = oddList->next;
        }
        else
        {
            evenList->next = temp;
            evenList = evenList->next;
        }
        count++;
        temp = temp->next;
    }
    evenList->next = NULL;
    oddList->next = evenListStart->next;
    return oddListStart->next;
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
    node1 = oddEvenList(node1);
    printLL(node1);
}