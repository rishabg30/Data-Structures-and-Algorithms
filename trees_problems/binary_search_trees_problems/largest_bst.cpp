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
/* In question we are given a Binary Tree, therefore we also need to check at every instance that is is a BST or not
therefore we will take minNodeValue and maxNodeValue variables to keep a track for verification of a BST */
class BST
{
public:
    int minNodeValue;
    int maxNodeValue;
    int size;
    BST()
    {
    }
    BST(int minNodeValue, int maxNodeValue, int size)
    {
        this->minNodeValue = minNodeValue;
        this->maxNodeValue = maxNodeValue;
        this->size = size;
    }
};
BST myLargestBST(TreeNode *root)
{
    // Base Condition
    if (root == NULL)
    {
        BST nullBST;
        nullBST.minNodeValue = 1e9;
        nullBST.maxNodeValue = -1e9;
        nullBST.size = 0;
        return nullBST;
    }

    /*We will use PostOrder traversal as we want left and right answer and then we will be computing our answer*/
    BST myans;
    BST left_subtree = myLargestBST(root->left);
    BST right_subtree = myLargestBST(root->right);

    // Checking if it is a valid BST
    if (left_subtree.maxNodeValue < root->val && right_subtree.minNodeValue > root->val)
    {
        // It's a valid BST
        myans.minNodeValue = min(left_subtree.minNodeValue, root->val);
        myans.maxNodeValue = max(right_subtree.maxNodeValue, root->val);
        myans.size = left_subtree.size + right_subtree.size + 1;
    }
    else
    {
        // It's not a valid BST
        myans.minNodeValue = -1e9;
        myans.maxNodeValue = 1e9;
        myans.size = max(left_subtree.size, right_subtree.size);
    }
    return myans;
}
int largestBst(TreeNode *root)
{
    BST ans = myLargestBST(root);
    return ans.size;
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
    cout << largestBst(root) << endl;
}