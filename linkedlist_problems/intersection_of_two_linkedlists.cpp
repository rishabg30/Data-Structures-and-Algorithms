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
/*
The idea behind this solution is if there is an intersection point the
two lists will definitely meet at this point. Therefore start iterating over
the list A,B and if A becomes NULL while B is present, mark A as B and
similarly for B also.
If they both becomes NULL this will signify there is no intersection point present.
At max A's length -> A + B
At max B's length -> B + A
*/
ListNode *getIntersectionNode(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    ListNode *curr1 = l1, *curr2 = l2;
    while (curr1 != curr2)
    {
        if (curr1 == NULL)
        {
            curr1 = l2;
        }
        else
        {
            curr1 = curr1->next;
        }
        if (curr2 == NULL)
        {
            curr2 = l1;
        }
        else
        {
            curr2 = curr2->next;
        }
    }
    return curr1;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(2N)
    Space complexity: O(1)
    */
    ListNode *node1_1 = new ListNode(4);
    ListNode *node1_2 = new ListNode(1);
    ListNode *node1_3 = new ListNode(8);
    ListNode *node1_4 = new ListNode(4);
    ListNode *node1_5 = new ListNode(5);

    ListNode *node2_1 = new ListNode(5);
    ListNode *node2_2 = new ListNode(6);
    ListNode *node2_3 = new ListNode(1);

    node1_1->next = node1_2;
    node1_2->next = node1_3;
    node1_3->next = node1_4;
    node1_4->next = node1_5;
    node2_1->next = node2_2;
    node2_2->next = node2_3;
    node2_3->next = node1_3;
    ListNode *node = getIntersectionNode(node1_1, node2_1);
    printLL(node);
}