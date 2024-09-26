#include <bits/stdc++.h>
using namespace std;
void printArray_1D(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
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
TreeNode *getRightMostNode(TreeNode *root, TreeNode *node)
{
    // Move till extreme right
    while (node->right != NULL && node->right != root)
    {
        node = node->right;
    }
    return node;
}
vector<int> morris_inOrder_traversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return {};
    }
    // Iterate till root exists
    while (root != NULL)
    {
        TreeNode *left_node = root->left;

        // If left node does not exist, print the ans and move to it's right node
        if (left_node == NULL)
        {
            ans.push_back(root->val);
            root = root->right;
        }
        // If left node exists, first find the rightmost node of this subtree and make a thread
        else
        {
            TreeNode *rightMostNode = getRightMostNode(root, left_node);

            // If rightMostNode->right is NULL, it means thread is not created
            // therefore create a thread and move to left node
            if (rightMostNode->right == NULL)
            {
                rightMostNode->right = root;
                root = root->left;
            }
            //  If rightMostNode->right is not NULL, it means thread is created
            // therefore remove the thread and move to right node
            else
            {
                rightMostNode->right = NULL;
                ans.push_back(root->val);
                root = root->right;
            }
        }
    }
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
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(7);
    root->left = node1;
    root->right = node2;

    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(8);
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;

    TreeNode *node6 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(5);
    TreeNode *node8 = new TreeNode(9);
    TreeNode *node9 = new TreeNode(10);
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;
    vector<int> ans = morris_inOrder_traversal(root);
    printArray_1D(ans);
}