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
ListNode *tempHead = NULL, *tempTail = NULL;
void addFirst(ListNode *head)
{
    ListNode *node = head;
    if (tempHead == NULL)
    {
        tempHead = tempTail = node;
    }
    else
    {
        node->next = tempHead;
        tempHead = node;
    }
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k == 1)
    {
        // Return back the original list
        return head;
    }
    int sizeLL = lengthLL(head);
    ListNode *actualHead = NULL, *actualTail = NULL, *curr = head;
    while (sizeLL >= k)
    {
        int temp = k;
        while (temp > 0)
        {
            ListNode *forwardNode = curr->next;
            curr->next = NULL;
            addFirst(curr);
            curr = forwardNode;
            temp--;
        }
        if (actualHead == NULL)
        {
            actualHead = tempHead;
            actualTail = tempTail;
        }
        else
        {
            actualTail->next = tempHead;
            actualTail = tempTail;
        }
        tempHead = tempTail = NULL;
        sizeLL = sizeLL - k;
    }
    actualTail->next = curr;
    return actualHead;
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
    ListNode *node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    int k;
    cin >> k;
    node1 = reverseKGroup(node1, k);
    printLL(node1);
}