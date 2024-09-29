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
void print_nodes_in_given_range(TreeNode *root, int low, int high, vector<int> &ans)
{
    // Base Condition
    if (root == NULL)
    {
        return;
    }
    /* We know inOrder traversal of a BST is always in sorted format. We will use this BST property*/

    // Move to left subtree and
    print_nodes_in_given_range(root->left, low, high, ans);

    // Compute the answer
    if (root->val >= low && root->val <= high)
    {
        ans.push_back(root->val);
    }

    // Move to right subtree
    print_nodes_in_given_range(root->right, low, high, ans);
}
vector<int> printNearNodes(TreeNode *root, int low, int high)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> ans;
    print_nodes_in_given_range(root, low, high, ans);
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
    int low, high;
    cin >> low >> high;
    vector<int> ans = printNearNodes(root, low, high);
    printArray_1D(ans);
}