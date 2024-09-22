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
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);

    while (q.size() != 0)
    {
        int size_of_queue = q.size();
        vector<int> curr_level;

        for (int i = 0; i < size_of_queue; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            curr_level.push_back(node->val);

            // If left child exists, push it to the queue
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            // If right child exists, push it to the queue
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        ans.push_back(curr_level);
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
    vector<vector<int>> ans = levelOrder(root);
    printArray_2D(ans);
}