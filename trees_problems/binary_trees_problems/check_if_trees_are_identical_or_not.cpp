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
bool isIdentical(TreeNode *root1, TreeNode *root2)
{
    // Base Conditions
    if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
    {
        return false;
    }
    // If root node itself is not same then trees are not identical
    if (root1->val != root2->val)
    {
        return false;
    }
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    // checking if left subtrees are identical
    bool check_left_subtrees = isIdentical(root1->left, root2->left);
    // checking if right subtrees are identical
    bool check_right_subtrees = isIdentical(root1->right, root2->right);
    return check_left_subtrees && check_right_subtrees;
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
    TreeNode *root1 = new TreeNode(1);
    TreeNode *node1_1 = new TreeNode(2);
    TreeNode *node2_1 = new TreeNode(7);
    root1->left = node1_1;
    root1->right = node2_1;

    TreeNode *node3_1 = new TreeNode(3);
    TreeNode *node4_1 = new TreeNode(6);
    TreeNode *node5_1 = new TreeNode(8);
    node1_1->left = node3_1;
    node1_1->right = node4_1;
    node2_1->right = node5_1;

    TreeNode *node6_1 = new TreeNode(4);
    TreeNode *node7_1 = new TreeNode(5);
    TreeNode *node8_1 = new TreeNode(9);
    TreeNode *node9_1 = new TreeNode(10);
    node3_1->left = node6_1;
    node3_1->right = node7_1;
    node5_1->left = node8_1;
    node5_1->right = node9_1;

    TreeNode *root2 = new TreeNode(1);
    TreeNode *node1_2 = new TreeNode(2);
    TreeNode *node2_2 = new TreeNode(7);
    root2->left = node1_2;
    root2->right = node2_2;

    TreeNode *node3_2 = new TreeNode(3);
    TreeNode *node4_2 = new TreeNode(6);
    TreeNode *node5_2 = new TreeNode(8);
    node1_2->left = node3_2;
    node1_2->right = node4_2;
    node2_2->right = node5_2;

    TreeNode *node6_2 = new TreeNode(4);
    TreeNode *node7_2 = new TreeNode(5);
    TreeNode *node8_2 = new TreeNode(9);
    TreeNode *node9_2 = new TreeNode(10);
    node3_2->left = node6_2;
    node3_2->right = node7_2;
    node5_2->left = node8_2;
    node5_2->right = node9_2;
    cout << isIdentical(root1, root2) << endl;
}