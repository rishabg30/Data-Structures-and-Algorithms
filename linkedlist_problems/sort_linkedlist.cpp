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
ListNode *middleLL(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // Base Cases
    if (l1 == NULL && l2 == NULL)
    {
        return l1;
    }
    if (l1 == NULL && l2 != NULL)
    {
        return l2;
    }
    if (l1 != NULL && l2 == NULL)
    {
        return l1;
    }
    ListNode *temp1 = l1, *temp2 = l2;
    ListNode *mergeList = new ListNode(-1), *curr = mergeList;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val <= temp2->val)
        {
            curr->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            curr->next = temp2;
            temp2 = temp2->next;
        }
        curr = curr->next;
    }
    if (temp1 != NULL)
    {
        curr->next = temp1;
    }
    if (temp2 != NULL)
    {
        curr->next = temp2;
    }
    return mergeList->next;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    /*
    We will apply same mergeSort concept here
    */
    ListNode *midNode = middleLL(head);
    ListNode *newNode = midNode->next;
    midNode->next = NULL;
    return mergeTwoLists(sortList(head), sortList(newNode));
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
    ListNode *node2 = new ListNode(5);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node1 = sortList(node1);
    printLL(node1);
}