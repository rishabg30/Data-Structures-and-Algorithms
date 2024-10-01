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
void findPreSuc(TreeNode *root, TreeNode *&pre, TreeNode *&suc, int key)
{
    if (root == NULL)
    {
        return;
    }
    // Computing left subtree
    findPreSuc(root->left, pre, suc, key);

    // Computing the answer
    if (root->val < key)
    {
        pre = root;
    }
    if (root->val > key && suc == NULL)
    {
        suc = root;
    }

    // Computing right subtree
    findPreSuc(root->right, pre, suc, key);
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
    TreeNode *pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, 7);
    cout << pre->val << " " << suc->val << endl;
}