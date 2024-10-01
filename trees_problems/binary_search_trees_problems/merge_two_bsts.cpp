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
void inOrder_traversal(TreeNode *root, vector<int> &bst)
{
    if (root == NULL)
    {
        return;
    }
    inOrder_traversal(root->left, bst);
    bst.push_back(root->val);
    inOrder_traversal(root->right, bst);
}
vector<int> merge(TreeNode *root1, TreeNode *root2)
{
    vector<int> bst1, bst2;
    // Step 1: find inOrder traversal for both bst's
    inOrder_traversal(root1, bst1);
    inOrder_traversal(root2, bst2);

    vector<int> ans;

    // Step 2: Use two pointer approach to merge them into third sorted vector
    int i = 0, j = 0;
    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] <= bst2[j])
        {
            ans.push_back(bst1[i]);
            i++;
        }
        else
        {
            ans.push_back(bst2[j]);
            j++;
        }
    }

    while (i < bst1.size())
    {
        ans.push_back(bst1[i]);
        i++;
    }
    while (j < bst2.size())
    {
        ans.push_back(bst2[j]);
        j++;
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
    Time complexity: O(N)
    Space complexity: O(N)
    */
    TreeNode *root1 = new TreeNode(5);
    TreeNode *node1_1 = new TreeNode(1);
    TreeNode *node2_1 = new TreeNode(10);
    TreeNode *node3_1 = new TreeNode(0);
    TreeNode *node4_1 = new TreeNode(4);
    TreeNode *node5_1 = new TreeNode(7);
    TreeNode *node6_1 = new TreeNode(9);
    root1->left = node1_1;
    root1->right = node2_1;
    node1_1->left = node3_1;
    node1_1->right = node4_1;
    node2_1->left = node5_1;
    node5_1->right = node6_1;

    TreeNode *root2 = new TreeNode(10);
    TreeNode *node7_1 = new TreeNode(7);
    TreeNode *node8_1 = new TreeNode(20);
    TreeNode *node9_1 = new TreeNode(4);
    TreeNode *node10_1 = new TreeNode(9);
    root2->left = node7_1;
    root2->right = node8_1;
    node7_1->left = node9_1;
    node7_1->right = node10_1;
    vector<int> ans = merge(root1, root2);
    printArray_1D(ans);
}