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
void min_difference_between_two_nodes(TreeNode *root, int &prev_node_val, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    // Applying inOrder traversal in a BST

    // Move to left subtree
    min_difference_between_two_nodes(root->left, prev_node_val, ans);
    // Compute the answer
    if (prev_node_val != -1)
    {
        ans = min(ans, root->val - prev_node_val);
    }
    prev_node_val = root->val;
    // Move to right subtree
    min_difference_between_two_nodes(root->right, prev_node_val, ans);
}
int minDiffInBST(TreeNode *root)
{
    /* We know that inOrder traversal of a BST is always in sorted increasing order,
    therefore minimum distance betwwen any two nodes will be equal to minimum distance between
    all consecutive nodes of a BST */

    if (root == NULL)
    {
        return 0;
    }
    int previous_node_val = -1;
    int ans = INT_MAX;
    min_difference_between_two_nodes(root, previous_node_val, ans);
    return ans;
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
    cout << minDiffInBST(root) << endl;
}