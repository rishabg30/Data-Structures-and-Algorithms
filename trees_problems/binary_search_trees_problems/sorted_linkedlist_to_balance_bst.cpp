#include <bits/stdc++.h>
using namespace std;
// Linked List
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};
// Tree
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};
TreeNode *buildBST(int startIdx, int endIdx, vector<int> &myTree)
{
    if (startIdx > endIdx)
    {
        return NULL;
    }
    // Finding mid element
    int mid = startIdx + (endIdx - startIdx + 1) / 2;

    // Create a root node
    TreeNode *root = new TreeNode(myTree[mid]);

    // Go to left subtree
    root->left = buildBST(startIdx, mid - 1, myTree);

    // Go to right subtree
    root->right = buildBST(mid + 1, endIdx, myTree);
    return root;
}
TreeNode *sortedListToBST(ListNode *head)
{
    // Step 1: Form a vector from a linkedlist
    vector<int> myTree;
    while (head != NULL)
    {
        myTree.push_back(head->val);
        head = head->next;
    }
    int startIdx = 0, endIdx = myTree.size() - 1;
    return buildBST(startIdx, endIdx, myTree);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(N)
    */
}