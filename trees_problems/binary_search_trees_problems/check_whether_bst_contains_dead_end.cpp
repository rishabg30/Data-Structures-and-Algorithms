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
bool check_dead_end(TreeNode *root, int minValue, int maxValue)
{
    // Base Condition
    if (root == NULL)
    {
        return false;
    }
    // if it's a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        if (root->val - minValue == 1 && maxValue - root->val == 1)
        {
            // it's a dead end
            return true;
        }
        else
        {
            return false;
        }
    }
    // Checking left and right subtrees
    bool left_dead_end = check_dead_end(root->left, minValue, root->val);
    bool right_dead_end = check_dead_end(root->right, root->val, maxValue);
    return left_dead_end || right_dead_end;
}
bool isDeadEnd(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    int minValue = 0, maxValue = 1e9;
    return check_dead_end(root, minValue, maxValue);
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
    cout << isDeadEnd(root) << endl;
}