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
vector<int> findSpiral(TreeNode *root)
{
    vector<int> ans;
    // We will be using the level order traversal here
    if (root == NULL)
    {
        return {};
    }
    queue<TreeNode *> q;
    q.push(root);

    int count = 0;
    while (q.size() > 0)
    {
        int curr_queue_size = q.size();
        vector<int> curr_level_nodes;
        for (int i = 0; i < curr_queue_size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (count == 0 || count & 1)
            {
                ans.push_back(node->val);
            }
            else
            {
                curr_level_nodes.push_back(node->val);
            }

            // Push left child in the queue if it exists
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            // Push right child in the queue if it exists
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        if (count != 0 && count % 2 == 0)
        {
            for (int i = curr_level_nodes.size() - 1; i >= 0; i--)
            {
                ans.push_back(curr_level_nodes[i]);
            }
        }
        count++;
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
    vector<int> ans = findSpiral(root);
    printArray_1D(ans);
}