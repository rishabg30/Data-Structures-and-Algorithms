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
TreeNode *deleteNode(TreeNode *root, int target)
{
    // Base Condition
    if (root == NULL)
    {
        return NULL;
    }
    // If root->val is greater than target, then move to left side
    if (root->val > target)
    {
        root->left = deleteNode(root->left, target);
        return root;
    }
    // If root->val is lesser than target, then move to right side
    else if (root->val < target)
    {
        root->right = deleteNode(root->right, target);
        return root;
    }
    // If root->val equals to target
    else
    {
        // Case 1: Deleting leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2: Only 1 child exists of node to be deleted
        else if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        {
            // Case 2.1: If left child only exists
            if (root->left != NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            // Case 2.2: If right child only exists
            else
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
        }
        // Case 3: Both child present of node to be deleted
        else
        {
            // Finding (root->left) rightmost node [greatest node in that subtree]
            TreeNode *child = root->left;
            TreeNode *parent = root;

            // Iterate till rightmost node
            while (child->right != NULL)
            {
                parent = child;
                child = child->right;
            }
            if (root != parent)
            {
                parent->right = child->left; // which basically pointing to NULL as child is going to be deleted from here
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
    return root;
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
    root = deleteNode(root, 12);
    inOrder_traversal(root);
}