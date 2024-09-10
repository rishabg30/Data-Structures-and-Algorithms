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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    if (l1 == NULL && l2 != NULL)
    {
        return l2;
    }
    if (l1 != NULL && l2 == NULL)
    {
        return l1;
    }
    ListNode *curr1 = l1, *curr2 = l2;
    ListNode *newList = new ListNode(-1), *newList_ptr = newList;
    int carry = 0;
    while (curr1 != NULL || curr2 != NULL || carry != 0)
    {
        int total_sum = 0;
        if (curr1 != NULL)
        {
            total_sum += curr1->val;
            curr1 = curr1->next;
        }
        if (curr2 != NULL)
        {
            total_sum += curr2->val;
            curr2 = curr2->next;
        }
        total_sum = total_sum + carry;
        ListNode *newNode = new ListNode(total_sum % 10);
        newList_ptr->next = newNode;
        carry = total_sum / 10;
        newList_ptr = newList_ptr->next;
    }
    return newList->next;
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
    ListNode *node1_1 = new ListNode(2);
    ListNode *node1_2 = new ListNode(4);
    ListNode *node1_3 = new ListNode(3);
    node1_1->next = node1_2;
    node1_2->next = node1_3;

    ListNode *node2_1 = new ListNode(5);
    ListNode *node2_2 = new ListNode(6);
    ListNode *node2_3 = new ListNode(4);
    node2_1->next = node2_2;
    node2_2->next = node2_3;
    ListNode *node = addTwoNumbers(node1_1, node2_1);
    printLL(node);
}