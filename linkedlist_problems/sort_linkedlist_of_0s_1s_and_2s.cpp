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
ListNode *segregate(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *temp = head;
    ListNode *zeros_list = new ListNode(-1), *zero_ptr = zeros_list;
    ListNode *ones_list = new ListNode(-1), *one_ptr = ones_list;
    ListNode *twos_list = new ListNode(-1), *two_ptr = twos_list;

    while (temp != NULL)
    {
        ListNode *forwardNode = temp->next;
        temp->next = NULL;
        int curr_val = temp->val;
        if (curr_val == 0)
        {
            zero_ptr->next = temp;
            zero_ptr = zero_ptr->next;
        }
        else if (curr_val == 1)
        {
            one_ptr->next = temp;
            one_ptr = one_ptr->next;
        }
        else
        {
            two_ptr->next = temp;
            two_ptr = two_ptr->next;
        }
        temp = forwardNode;
    }
    one_ptr->next = twos_list->next;
    zero_ptr->next = ones_list->next;
    return zeros_list->next;
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
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(1);
    ListNode *node5 = new ListNode(2);
    ListNode *node6 = new ListNode(0);
    ListNode *node7 = new ListNode(2);
    ListNode *node8 = new ListNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node1 = segregate(node1);
    printLL(node1);
}