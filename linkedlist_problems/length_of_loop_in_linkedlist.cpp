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
int countNodesinLoop(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 0;
    }
    /*
    We use the same tortoise-hare algorithm here also. Moving slow pointer
    by one step and fast pointer by two steps. At any point slow and fast
    pointer meets, this means there is cycle [loop] present in a linkedlist
    otherwise fast will become NULL.
    Once loop is present and confirmed, create a new temp pointer and start iterating
    until it reaches the same point = length of loop in a linkedlist
    */
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            // Count the number of nodes in the loop
            int countCycles = 1;
            ListNode *temp = slow;
            while (temp->next != slow)
            {
                temp = temp->next;
                countCycles++;
            }
            return countCycles;
        }
    }
    return 0;
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
    cout << countNodesinLoop(node1);
}