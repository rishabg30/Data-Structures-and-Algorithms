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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL || (head->next == NULL && n == 1))
    {
        return NULL;
    }
    /*
    The algorithm says that, maintain a slow and fast pointer. Initally till n steps, iterate
    fast pointer by 1 step. After n steps, start iterating both slow and fast pointer by 1 step.
    As soon as fast->next == NULL, we are 1 step behind the node to be deleted
    */
    ListNode *slow = head, *fast = head;
    while (n--)
    {
        fast = fast->next;
        if (fast == NULL)
        {
            return head->next;
        }
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
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
    ListNode *node = removeNthFromEnd(node1, pos);
    printLL(node);
}