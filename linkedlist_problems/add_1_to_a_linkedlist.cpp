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
ListNode *reverseLL(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *forwardNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forwardNode;
    }
    return prev;
}
ListNode *addOne(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    ListNode *reverseList = reverseLL(head);
    ListNode *temp = reverseList;

    int carry = 0;
    while (true)
    {
        /* If number is less than 9, simply add 1 and update node value
         */
        int curr_value = temp->val;
        if (curr_value < 9)
        {
            curr_value++;
            temp->val = curr_value;
            break;
        }
        else
        {
            /* We got something like 99.... therefore iterate will carry is not dissolved
             */
            carry++;
            while (temp != NULL && carry != 0)
            {
                curr_value = temp->val + 1;
                temp->val = curr_value % 10;
                carry = curr_value / 10;
                if (temp->next != NULL)
                {
                    temp = temp->next;
                }
                else
                {
                    break;
                }
            }
            break;
        }
        temp = temp->next;
    }
    if (carry != 0)
    {
        temp->next = new ListNode(1);
        temp = temp->next;
    }
    return reverseLL(reverseList);
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
    ListNode *node1 = new ListNode(9);
    ListNode *node2 = new ListNode(9);
    ListNode *node3 = new ListNode(9);
    node1->next = node2;
    node2->next = node3;
    node1 = addOne(node1);
    printLL(node1);
}