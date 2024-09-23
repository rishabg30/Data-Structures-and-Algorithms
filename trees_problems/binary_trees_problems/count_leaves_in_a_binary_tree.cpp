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
int countLeaves(TreeNode *root)
{
    // Base Condition
    if (root == NULL)
    {
        return 0;
    }
    // For a node to be a leaf node -> it's left and right child should both be NULL
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    // Leaf nodes in left binary tree
    int count_left_leaf_nodes = countLeaves(root->left);
    // Leaf nodes in right binary tree
    int count_right_leaf_nodes = countLeaves(root->right);
    return count_left_leaf_nodes + count_right_leaf_nodes;
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
    cout << countLeaves(root) << endl;
}