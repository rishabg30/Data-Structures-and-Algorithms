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
TreeNode *insert_node(TreeNode *root, int target)
{
    // If root itself is NULL, make target as root node
    if (root == NULL)
    {
        TreeNode *node = new TreeNode(target);
        return node;
    }
    // Check if target's value is less than or greater than root
    if (target < root->val)
    {
        // Move to left side
        root->left = insert_node(root->left, target);
    }
    else
    {
        // Move to right side
        root->right = insert_node(root->right, target);
    }
    return root;
}
void inOrder_traversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    // First move to left side
    inOrder_traversal(root->left);
    // Second print the root node
    cout << root->val << " ";
    // Third move to right side
    inOrder_traversal(root->right);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N * N)
    Space complexity: O(N)
    */
    vector<int> arr = {6, 3, 11, 5, 7, 18, 12, 2};
    TreeNode *root = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        root = insert_node(root, arr[i]);
    }

    // inOrder traversal
    inOrder_traversal(root);
}