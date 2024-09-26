#include <bits/stdc++.h>
using namespace std;
void printArray_2D(vector<vector<int>> &arr)
{
    for (auto it : arr)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
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
void root_to_node_paths(TreeNode *root, vector<vector<int>> &ans, vector<int> &ds)
{
    // Base Conditions
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        // Add this last leaf node
        ds.push_back(root->val);
        ans.push_back(ds);
        // Remove this last leaf node [Backtrack]
        ds.pop_back();
        return;
    }
    // Applying PreOrder traversal [Root, Left, Right]
    ds.push_back(root->val);
    root_to_node_paths(root->left, ans, ds);
    root_to_node_paths(root->right, ans, ds);
    ds.pop_back();
}
vector<vector<int>> Paths(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return {{}};
    }
    vector<int> ds;
    root_to_node_paths(root, ans, ds);
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
    vector<vector<int>> ans = Paths(root);
    printArray_2D(ans);
}