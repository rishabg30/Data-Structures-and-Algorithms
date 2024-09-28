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
void preOrder_traversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preOrder_traversal(root->left);
    preOrder_traversal(root->right);
}
TreeNode *array_to_bst(vector<int> &arr, int startIdx, int endIdx)
{
    if (startIdx > endIdx)
    {
        return NULL;
    }
    /* To create a BST which is height balanced, we will take root node as mid element of array */
    int mid = (startIdx + endIdx) / 2;

    // Create a root node
    TreeNode *root = new TreeNode(arr[mid]);

    // Go to the left subtree
    root->left = array_to_bst(arr, startIdx, mid - 1);
    // Go to the right subtree
    root->right = array_to_bst(arr, mid + 1, endIdx);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &arr)
{
    int n = arr.size(), low = 0, high = n - 1;
    return array_to_bst(arr, low, high);
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
    TreeNode *root = sortedArrayToBST(arr);
    // preOrder traversal
    preOrder_traversal(root);
}