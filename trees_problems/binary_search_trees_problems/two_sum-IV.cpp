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
void inOrder_traverse(TreeNode *root, vector<int> &bst)
{
    if (root == NULL)
    {
        return;
    }
    inOrder_traverse(root->left, bst);
    bst.push_back(root->val);
    inOrder_traverse(root->right, bst);
}
bool findTarget(TreeNode *root, int k)
{
    /* We know that inOrder traversal of a Binary Tree is always in sorted format.
    therefore we will store inOrder in a vector and use two pointer approach to find if two nodes
    have sum equals to k */
    vector<int> bst;
    inOrder_traverse(root, bst);

    int i = 0, j = bst.size() - 1;
    while (i < j)
    {
        if (bst[i] + bst[j] < k)
        {
            i++;
        }
        else if (bst[i] + bst[j] > k)
        {
            j--;
        }
        else
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
    Time complexity: O()
    Space complexity: O()
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
    cout << findTarget(root, 20);
}