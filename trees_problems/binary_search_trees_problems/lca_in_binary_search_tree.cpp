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
TreeNode *lca_in_bst(TreeNode *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    // If both n1 and n2 value is less than root, move to left side
    if (n1 < root->val && n2 < root->val)
    {
        return lca_in_bst(root->left, n1, n2);
    }
    // If both n1 and n2 value is greater than root, move to right
    else if (n1 > root->val && n2 > root->val)
    {
        return lca_in_bst(root->right, n1, n2);
    }
    // If both gets separated, this is only the LCA
    else
    {
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
    TreeNode *ans = lca_in_bst(root, node4->val, node8->val);
    cout << ans->val << endl;
}