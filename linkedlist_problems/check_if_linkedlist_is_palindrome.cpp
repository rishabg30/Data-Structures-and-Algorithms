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
ListNode *reverseLL(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *temp = head;
    while (temp != NULL)
    {
        ListNode *nextElement = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextElement;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    if (head == NULL)
    {
        return true;
    }
    ListNode *middlePoint = middleLL(head);
    ListNode *reverseList = reverseLL(middlePoint->next);
    middlePoint->next = reverseList;

    ListNode *startptr = head;
    while (reverseList != NULL)
    {
        if (startptr->val != reverseList->val)
        {
            return false;
        }
        startptr = startptr->next;
        reverseList = reverseList->next;
    }
    return true;
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
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(2);
    ListNode *node6 = new ListNode(0);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    cout << isPalindrome(node1) << endl;
}