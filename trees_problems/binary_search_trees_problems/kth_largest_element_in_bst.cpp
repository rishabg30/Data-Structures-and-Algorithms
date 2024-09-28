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
void kth_largest_element(TreeNode *root, int k, int &ans, int &count)
{
    if (root == NULL)
    {
        return;
    }
    // Applying inOrder traversal in a BST in reverse order as we need to find the largest element [Right, Root, Left]

    // Move to right subtree
    kth_largest_element(root->right, k, ans, count);

    // Compute the answer
    if (count == k)
    {
        // This is our kth largest element
        ans = root->val;
    }
    count++;
    // Move to left subtree
    kth_largest_element(root->left, k, ans, count);
}
int kthLargest(TreeNode *root, int k)
{
    /* We know that inOrder traversal of a BST is always in sorted increasing order,
   therefore kth largest element of BST will only be present at the last kth spot of the
   inOrder traversed tree */

    int ans = 0, count = 1;
    kth_largest_element(root, k, ans, count);
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
    cout << kthLargest(root, 3) << endl;
}