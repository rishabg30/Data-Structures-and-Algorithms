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
bool checkParent(TreeNode *root, int a, int b)
{
    if (root == NULL)
    {
        return false;
    }
    // Base Condition: Both left and right children must be present
    if (root->left && root->right)
    {
        // check if their left and right children are equal or different
        if ((root->left->val == a && root->right->val == b) || (root->left->val == b && root->right->val == a))
        {
            return true;
        }
    }
    return checkParent(root->left, a, b) || checkParent(root->right, a, b);
}
void levelOrderTraversal(TreeNode *root, int node, int &currDepth)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);

    int curr_level = 0;
    while (q.size() > 0)
    {
        int size_of_queue = q.size();
        for (int i = 0; i < size_of_queue; i++)
        {
            TreeNode *curr_node = q.front();
            q.pop();
            if (curr_node->val == node)
            {
                currDepth = curr_level;
            }
            // if left child exists, push it to the queue
            if (curr_node->left)
            {
                q.push(curr_node->left);
            }
            // if right child exists, push it to the queue
            if (curr_node->right)
            {
                q.push(curr_node->right);
            }
        }
        curr_level++;
    }
}
bool isCousins(TreeNode *root, int a, int b)
{
    // Two nodes are said to be cousins if they are present at the same level and their parents are different.
    if (root == NULL)
    {
        return false;
    }
    // Firstly finding out if both are present at the same level or not
    int depth_of_a = -1, depth_of_b = -1;
    levelOrderTraversal(root, a, depth_of_a);
    levelOrderTraversal(root, b, depth_of_b);
    if ((depth_of_a != depth_of_b) || (depth_of_a == -1) || (depth_of_b == -1))
    {
        return false;
    }
    // Secondly check if their parents are different or not
    bool sameParent = checkParent(root, a, b);
    if (sameParent == true)
    {
        return false;
    }
    return true;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(N)
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
    int a, b;
    cin >> a >> b;
    cout << isCousins(root, a, b) << endl;
}