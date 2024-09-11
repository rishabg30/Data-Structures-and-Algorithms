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
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k < 1)
    {
        return head;
    }
    /* The idea is we will form a cyclic list connecting last
    node with the starting node
    */
    ListNode *curr = head, *rotatedList = head;
    int sizeLL = 1;
    while (curr->next != NULL)
    {
        curr = curr->next;
        sizeLL++;
    }
    // Making the list circular
    curr->next = head;
    k = k % sizeLL; // If k > size of list, then it will be handled.
    if (k == 0)
    {
        // Break the cycle
        curr->next = NULL;
        return head;
    }

    int counter = 1;
    ListNode *temp = head;
    while (counter < sizeLL - k)
    {
        temp = temp->next;
        counter++;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O()
    Space complexity: O()
    */
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    int k;
    cin >> k;
    node1 = rotateRight(node1, k);
    printLL(node1);
}