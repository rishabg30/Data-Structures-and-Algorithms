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

/*
Time complexity: O(N)
Space complexity: O(N)
*/
/*
TreeNode *first_node = NULL, *second_node = NULL, *third_node = NULL, *fourth_node = NULL;
void inOrder_traverse(TreeNode *root, vector<TreeNode *> &bst)
{
    if (root == NULL)
    {
        return;
    }
    inOrder_traverse(root->left, bst);
    bst.push_back(root);
    inOrder_traverse(root->right, bst);
}
void recoverTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    vector<TreeNode *> bst;

    // Applying inOrder traversal and storing in bst vector
    inOrder_traverse(root, bst);

    // Iterate on bst vector and find the faulty nodes
    for (int i = 1; i < bst.size(); i++)
    {
        if (bst[i]->val < bst[i - 1]->val)
        {
            // When faulty nodes are not connected to each other
            if (first_node == NULL && second_node == NULL)
            {
                first_node = bst[i - 1];
                second_node = bst[i];
            }
            // When faulty nodes are connected to each other
            else
            {
                third_node = bst[i - 1];
                fourth_node = bst[i];
            }
        }
    }
    // When faulty nodes are not connected to each other
    if (third_node != NULL && fourth_node != NULL)
    {
        swap(first_node->val, fourth_node->val);
    }
    // When faulty nodes are connected to each other
    else
    {
        swap(first_node->val, second_node->val);
    }
}
*/

void recoverTree(TreeNode *root)
{
    /*
    Time complexity: O(N)
    Space complexity: O(1)
    */

    if (root == NULL)
    {
        return;
    }
    TreeNode *curr = NULL;
    TreeNode *first_node = NULL, *second_node = NULL, *last_node = NULL, *present_node = NULL;

    while (root != NULL)
    {
        // If left child does not exist, move to the right child
        if (root->left == NULL)
        {
            last_node = present_node;
            present_node = root;
            root = root->right;

            // Compare the values for last and present
            if (last_node && last_node->val > present_node->val)
            {
                // We encountered the mistake first time
                if (first_node == NULL)
                {
                    first_node = last_node;
                    second_node = present_node;
                }
                else
                {
                    // We again encounter the mistake
                    second_node = present_node;
                }
            }
        }
        else
        {
            curr = root->left;
            while (curr->right != NULL && curr->right != root)
            {
                curr = curr->right;
            }
            // Thread creation
            if (curr->right == NULL)
            {
                curr->right = root;
                root = root->left;
            }
            // Thread is already created, therefore remove the link and move to right side
            else
            {
                curr->right = NULL;
                last_node = present_node;
                present_node = root;

                // Compare the values for last and present
                if (last_node && last_node->val > present_node->val)
                {
                    // We encountered the mistake first time
                    if (first_node == NULL)
                    {
                        first_node = last_node;
                        second_node = present_node;
                    }
                    else
                    {
                        // We again encounter the mistake
                        second_node = present_node;
                    }
                }
                root = root->right;
            }
        }
    }
    swap(first_node->val, second_node->val);
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
    recoverTree(root);
}