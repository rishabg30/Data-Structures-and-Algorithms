#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
void inOrder_traversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    // First move to left side
    inOrder_traversal(root->left);
    // Second print the root node
    cout << root->val << " ";
    // Third move to right side
    inOrder_traversal(root->right);
}
TreeNode *searchBST(TreeNode *root, int target)
{
    // Base Condition
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == target)
    {
        return root;
    }
    // Search in left subtree if root's val is greater than target
    if (root->val > target)
    {
        return searchBST(root->left, target);
    }
    // Search in right subtree if root's val is less than target
    else
    {
        return searchBST(root->right, target);
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(LogN)
    Space complexity: O(1)
    */
    TreeNode *root = new TreeNode(8);
    TreeNode *node1 = new TreeNode(6);
    TreeNode *node2 = new TreeNode(12);
    root->left = node1;
    root->right = node2;

    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(7);
    TreeNode *node5 = new TreeNode(9);
    TreeNode *node6 = new TreeNode(14);
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    TreeNode *node7 = new TreeNode(3);
    TreeNode *node8 = new TreeNode(5);
    node3->left = node7;
    node3->right = node8;
    TreeNode *node = searchBST(root, node2->val);
    inOrder_traversal(node);
}