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
TreeNode *build_bst(vector<int> &preorder, int &startIdx, int minValue, int maxValue)
{
    // Base Condition
    if (startIdx == preorder.size() || preorder[startIdx] < minValue || preorder[startIdx] > maxValue)
    {
        return NULL;
    }
    // Step 1: Create a root node and move to next index of preorder vector
    TreeNode *root = new TreeNode(preorder[startIdx++]);

    // Step 2: Move to left subtree and update the range
    root->left = build_bst(preorder, startIdx, minValue, root->val);

    // Step 3: Move to right subtree and update the range
    root->right = build_bst(preorder, startIdx, root->val, maxValue);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int n = preorder.size();
    int startIdx = 0, minValue = -1e9, maxValue = 1e9;
    return build_bst(preorder, startIdx, minValue, maxValue);
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
    TreeNode *root = bstFromPreorder(arr);
    inOrder_traversal(root);
}