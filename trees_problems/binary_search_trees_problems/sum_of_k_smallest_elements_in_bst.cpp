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
void sum_k_smallest_elements(TreeNode *root, int k, int &ans, int &count)
{
    if (root == NULL)
    {
        return;
    }
    // Applying inOrder traversal in a BST

    // Move to left subtree
    sum_k_smallest_elements(root->left, k, ans, count);

    // Compute the answer
    if (count < k)
    {
        ans = ans + root->val;
    }
    count++;
    // Move to right subtree
    sum_k_smallest_elements(root->right, k, ans, count);
}
int sum_of_k_smallest_elements(TreeNode *root, int k)
{
    /* We know that inOrder traversal of a BST is always in sorted increasing order,
   therefore smallest elements of BST will only be present at the first three spots of the
   inOrder traversed tree */

    int ans = 0, count = 0;
    sum_k_smallest_elements(root, k, ans, count);
    return ans;
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
    cout << sum_of_k_smallest_elements(root, 3) << endl;
}