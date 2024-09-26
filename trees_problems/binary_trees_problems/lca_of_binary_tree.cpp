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
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // Base Conditions
    // if we encounter NULL node or any p / q node, we will return that node only signifying we got the node from here
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    // call for left subtree
    TreeNode *leftSubtree = lowestCommonAncestor(root->left, p, q);
    // call for right subtree
    TreeNode *rightSubtree = lowestCommonAncestor(root->right, p, q);

    if (leftSubtree == NULL)
    {
        return rightSubtree;
    }
    else if (rightSubtree == NULL)
    {
        return leftSubtree;
    }
    else
    {
        // If both left subtree and right subtree are not NULL, this means this is the LCA we are looking for
        return root;
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
    TreeNode *lca = lowestCommonAncestor(root, node5, node8);
    cout << lca->val << endl;
}