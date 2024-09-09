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
bool hasCycle(ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }
    ListNode *slow = head, *fast = head;

    /*
    We use the same tortoise-hare algorithm here also. Moving slow pointer
    by one step and fast pointer by two steps. At any point slow and fast
    pointer meets, this means there is cycle [loop] present in a linkedlist
    otherwise fast will become NULL
    */
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
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
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    cout << hasCycle(node1) << endl;
}