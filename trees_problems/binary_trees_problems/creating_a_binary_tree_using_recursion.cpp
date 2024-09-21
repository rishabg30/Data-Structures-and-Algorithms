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
TreeNode *creatBinaryTree()
{
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }

    TreeNode *node = new TreeNode(x);

    // Creating left child of binary tree
    cout << "Enter the left child of node: " << endl;
    node->left = creatBinaryTree();

    // Creating right child of binary tree
    cout << "Enter the right child of node: " << endl;
    node->right = creatBinaryTree();
    return node;
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

    cout << "Enter the root node: " << endl;
    TreeNode *root;
    root = creatBinaryTree();
}