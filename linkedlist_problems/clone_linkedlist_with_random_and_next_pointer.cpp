#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *random;
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
        random = NULL;
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
/* M-1: Using Hashmaps [extra space] */
/*
ListNode *copyList(ListNode *head)
{
    ListNode *temp = head;
    map<ListNode *, ListNode *> mp;

    // Step 1: Iterate in the list and create new node
    while (temp != NULL)
    {
        ListNode *newNode = new ListNode(temp->val);
        mp[temp] = newNode;
        temp = temp->next;
    }

    // Step 2: Again iterate in the list and connect next and random pointers
    temp = head;
    while (temp != NULL)
    {
        ListNode *copyNode = mp[temp];
        copyNode->next = temp->next;
        copyNode->random = temp->random;
        temp = temp->next;
    }
    return mp[head];
}
*/

/* M-2: Without using any extra space */
ListNode *copyList(ListNode *head)
{
    // Step 1: Inserting the copied nodes in between original list
    ListNode *temp = head;
    while (temp != NULL)
    {
        ListNode *copyNode = new ListNode(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }

    // Step 2: Connect the random pointers
    temp = head;
    while (temp != NULL)
    {
        ListNode *copyNode = temp->next;
        if (temp->random)
        {
            copyNode->random = temp->random->next;
        }
        else
        {
            copyNode->random = NULL;
        }
        temp = temp->next->next;
    }

    // Step 3: Connect the next pointers
    ListNode *newList = new ListNode(-1), *curr = newList;
    temp = head;
    while (temp != NULL)
    {
        curr->next = temp->next;
        temp->next = temp->next->next; // Removing the link between original node and copied node
        curr = curr->next;
        temp = temp->next;
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
    M-1
    Time complexity: O(2N)
    Space complexity: O(N)

    M-2
    Time complexity: O(3N)
    Space complexity: O(1)
    */
    ListNode *node1 = new ListNode(7);
    ListNode *node2 = new ListNode(13);
    ListNode *node3 = new ListNode(11);
    ListNode *node4 = new ListNode(10);
    ListNode *node5 = new ListNode(1);

    // next pointers
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // random pointers
    node1->random = NULL;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;
    ListNode *copiedList = copyList(node1);
    printLL(copiedList);
}