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
void check_common_nodes(TreeNode *root, map<int, int> &mp, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    check_common_nodes(root->left, mp, ans);
    if (mp.find(root->val) != mp.end())
    {
        ans.push_back(root->val);
    }
    check_common_nodes(root->right, mp, ans);
}
void inOrder_traversal(TreeNode *root, map<int, int> &mp)
{
    if (root == NULL)
    {
        return;
    }
    inOrder_traversal(root->left, mp);
    mp[root->val]++;
    inOrder_traversal(root->right, mp);
}
vector<int> findCommon(TreeNode *root1, TreeNode *root2)
{
    map<int, int> mp;
    inOrder_traversal(root1, mp);

    vector<int> ans;
    check_common_nodes(root2, mp, ans);
    return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Here n1 are total nodes of 1st BST and n2 are total nodes of 2nd BST
    Time complexity: O(n1 + n2)
    Space complexity: O(n1 + n2)
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
    vector<int> ans = findCommon(root1, root2);
    printArray_1D(ans);
}