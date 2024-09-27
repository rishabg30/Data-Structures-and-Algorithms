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
TreeNode *getRightMostNode(TreeNode *node)
{
    // Move till extreme right
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}
void flatten_binaryTree_to_linkedlist(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    // Iterate till root exists
    while (root != NULL)
    {
        // If left part does not exist, simply move to right node
        if (root->left == NULL)
        {
            root = root->right;
        }
        // If left part exist, find it's rightmost node and connect to root's right
        else
        {
            TreeNode *rightMostNode = getRightMostNode(root->left);
            // Connect rightmost node to root's right node
            rightMostNode->right = root->right;

            // Connect root's right to root's left and delete root's left link from root
            root->right = root->left;
            root->left = NULL;

            // Now move root to root's right for next iteration
            root = root->right;
        }
    }
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
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(7);
    root->left = node1;
    root->right = node2;

    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(8);
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;

    TreeNode *node6 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(5);
    TreeNode *node8 = new TreeNode(9);
    TreeNode *node9 = new TreeNode(10);
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;
    flatten_binaryTree_to_linkedlist(root);
}