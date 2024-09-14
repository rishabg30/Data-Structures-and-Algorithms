#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
        bottom = NULL;
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
        temp = temp->bottom;
    }
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(-1);
    ListNode *tail = head;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            tail->bottom = l1;
            l1 = l1->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }
        else
        {
            tail->bottom = l2;
            l2 = l2->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }
    }
    if (l1 != NULL)
    {
        tail->bottom = l1;
    }
    if (l2 != NULL)
    {
        tail->bottom = l2;
    }
    return head->bottom;
}
ListNode *flatten(ListNode *root)
{
    ListNode *head1, *head2, *head3;
    while (root->next != NULL)
    {
        head1 = root;
        head2 = root->next;
        head3 = root->next->next;

        // Break the connection between 1st and 2nd list
        head1->next = head2->next = NULL;

        // Merge the two lists
        root = mergeTwoLists(head1, head2);

        // Make connection between this newly created list and next list
        root->next = head3;
    }
    return root;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time taken to merge two sorted lists [n + n = 2n]
    merging with third list [2n + n = 3n], 4n,5n......nm

    Total time complexity = [2n + 3n + 4n + .... + nm] = (n^2)m
    where n is length of the lists and m are total number of lists
    Time complexity: O((n^2)m)
    Space complexity: O(1)
    */
    ListNode *node1_1 = new ListNode(5);
    ListNode *node1_2 = new ListNode(7);
    ListNode *node1_3 = new ListNode(8);
    ListNode *node1_4 = new ListNode(30);
    node1_1->bottom = node1_2;
    node1_2->bottom = node1_3;
    node1_3->bottom = node1_4;

    ListNode *node2_1 = new ListNode(10);
    ListNode *node2_2 = new ListNode(20);
    node2_1->bottom = node2_2;
    node1_1->next = node2_1;

    ListNode *node3_1 = new ListNode(19);
    ListNode *node3_2 = new ListNode(22);
    ListNode *node3_3 = new ListNode(50);
    node3_1->bottom = node3_2;
    node3_2->bottom = node3_3;
    node2_1->next = node3_1;

    node1_1 = flatten(node1_1);
    printLL(node1_1);
}