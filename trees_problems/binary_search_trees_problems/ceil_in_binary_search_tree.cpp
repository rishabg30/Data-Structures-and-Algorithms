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
// Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.
int findCeil(TreeNode *root, int x)
{
    int ans = -1;
    if (root == NULL)
    {
        return 0;
    }

    while (root != NULL)
    {
        if (root->val == x)
        {
            return root->val;
        }
        // If root's value is greater than x, update the ceil to root's value and move to left side to see if we can find better answer
        if (root->val > x)
        {
            ans = root->val;
            root = root->left;
        }
        // If root's value is lesser than x, move to the right side of the tree
        else
        {
            root = root->right;
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
    Time complexity: O(LogN)
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
    cout << findCeil(root, 2) << endl;
}