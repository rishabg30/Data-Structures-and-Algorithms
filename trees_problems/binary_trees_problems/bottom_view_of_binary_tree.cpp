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
vector<int> bottomView(TreeNode *root)
{
    vector<int> ans;
    // We will be using level order traversal only
    if (root == NULL)
    {
        return {};
    }

    // queue will store {node's x_axis, node}
    queue<pair<int, TreeNode *>> q;
    q.push(make_pair(0, root));

    // require a map storing {node's x_axis, node}
    map<int, TreeNode *> mp;
    while (q.size() > 0)
    {
        int size_of_queue = q.size();
        for (int i = 0; i < size_of_queue; i++)
        {
            int curr_node_x_axis = q.front().first;
            TreeNode *curr_node = q.front().second;
            q.pop();

            // If we find node for the last time in a particular x_axis, that should be one of our answers
            mp[curr_node_x_axis] = curr_node;

            // if left child exists, push it in the queue
            if (curr_node->left)
            {
                q.push({curr_node_x_axis - 1, curr_node->left});
            }
            // if right child exists, push it in the queue
            if (curr_node->right)
            {
                q.push({curr_node_x_axis + 1, curr_node->right});
            }
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second->val);
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
    vector<int> ans = bottomView(root);
    printArray_1D(ans);
}