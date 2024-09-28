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
void inOrder_traversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    // First move to left side
    inOrder_traversal(root->left);
    // Second print the root node
    cout << root->val << " ";
    // Third move to right side
    inOrder_traversal(root->right);
}
TreeNode *build_bst(vector<int> &postorder, int &startIdx, int minValue, int maxValue)
{
    // Base Condition
    if (startIdx < 0 || postorder[startIdx] < minValue || postorder[startIdx] > maxValue)
    {
        return NULL;
    }
    /* PostOrder is: Left, Right, Root, after reversing we get Root, Right Left */

    // Step 1: Create a root node and move to previous index of postorder vector
    TreeNode *root = new TreeNode(postorder[startIdx--]);
    // Step 2: Move to right subtree and update the range
    root->right = build_bst(postorder, startIdx, root->val, maxValue);
    // Step 3: Move to left subtree and update the range
    root->left = build_bst(postorder, startIdx, minValue, root->val);

    return root;
}
TreeNode *bstFromPostorder(vector<int> &postorder)
{
    int n = postorder.size();
    int startIdx = n - 1, minValue = -1e9, maxValue = 1e9;
    return build_bst(postorder, startIdx, minValue, maxValue);
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    TreeNode *root = bstFromPostorder(arr);
    inOrder_traversal(root);
}