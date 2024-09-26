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
int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    unsigned long long ans = 0;
    // we will use queue data structure and be using level order traversal
    queue<pair<TreeNode *, unsigned long long>> q; // will store {node, index}
    q.push({root, 0});

    while (q.size() > 0)
    {
        unsigned long long size_of_queue = q.size();
        unsigned long long first_node_index = 0, last_node_index = 0;
        for (unsigned long long i = 0; i < size_of_queue; i++)
        {
            TreeNode *node = q.front().first;
            unsigned long long curr_node_index = q.front().second;
            q.pop();
            // if it's a first node of that level, store the first node index
            if (i == 0)
            {
                first_node_index = curr_node_index;
            }
            if (i == size_of_queue - 1)
            {
                last_node_index = curr_node_index;
            }
            // if left child exists, push it into queue
            if (node->left)
            {
                q.push({node->left, (unsigned long long)2 * curr_node_index + 1});
            }
            // if right child exists, push it into queue
            if (node->right)
            {
                q.push({node->right, (unsigned long long)2 * curr_node_index + 2});
            }
        }
        ans = max(ans, last_node_index - first_node_index + 1);
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
    cout << widthOfBinaryTree(root) << endl;
}