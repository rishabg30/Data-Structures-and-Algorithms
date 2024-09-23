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
int height_of_tree(TreeNode *root, bool &curr_balanced)
{
    // Base Condition
    if (root == NULL)
    {
        return 0;
    }
    // calculating left subtree height
    int left_subtree_height = height_of_tree(root->left, curr_balanced);
    // Calculating right subtree height
    int right_subtree_height = height_of_tree(root->right, curr_balanced);
    // checking if they are balanced or not
    if (abs(left_subtree_height - right_subtree_height) > 1)
    {
        return false;
    }
    return max(left_subtree_height, right_subtree_height) + 1;
}
bool isBalanced(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool curr_balanced = true;
    height_of_tree(root, curr_balanced);
    return curr_balanced;
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
    cout << isBalanced(root) << endl;
}