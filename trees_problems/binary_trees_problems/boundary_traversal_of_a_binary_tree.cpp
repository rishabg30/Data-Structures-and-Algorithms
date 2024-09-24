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
bool node_is_leaf(TreeNode *node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return true;
    }
    return false;
}
void leftView_of_binary_tree(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (node_is_leaf(root) == false)
    {
        ans.push_back(root->val);
    }
    if (root->left)
    {
        leftView_of_binary_tree(root->left, ans);
    }
    else
    {
        leftView_of_binary_tree(root->right, ans);
    }
}
void leafNodes_of_binary_tree(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    // Condition for a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->val);
        return;
    }
    // check left subtree
    leafNodes_of_binary_tree(root->left, ans);
    // check right subtree
    leafNodes_of_binary_tree(root->right, ans);
}
void rightView_of_binary_tree(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right)
    {
        rightView_of_binary_tree(root->right, ans);
    }
    else
    {
        rightView_of_binary_tree(root->left, ans);
    }
    if (node_is_leaf(root) == false)
    {
        ans.push_back(root->val);
    }
}
vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> ans;
    // For boundary traversal, we require left view of tree, leaf nodes and right view of tree in reverse order
    if (root == NULL)
    {
        return {};
    }
    if (node_is_leaf(root) == false)
    {
        ans.push_back(root->val);
    }
    leftView_of_binary_tree(root->left, ans);
    leafNodes_of_binary_tree(root, ans);
    rightView_of_binary_tree(root->right, ans);
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
    vector<int> ans = boundaryTraversal(root);
    printArray_1D(ans);
}