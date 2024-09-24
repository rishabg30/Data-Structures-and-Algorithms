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
vector<int> verticalOrder(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return {};
    }
    // we will maintain a queue storing {{node's_x_axis, node's_y_axis}, node}
    queue<pair<pair<int, int>, TreeNode *>> q;
    multimap<pair<int, int>, TreeNode *> mp;

    q.push({{0, 0}, root});
    while (q.size() > 0)
    {
        pair<pair<int, int>, TreeNode *> p = q.front();
        q.pop();
        int node_x_axis = p.first.first;
        int node_y_axis = p.first.second;
        TreeNode *curr_node = p.second;
        mp.insert({{node_x_axis, node_y_axis}, curr_node});

        // if left child exists, push it into the queue
        if (curr_node->left)
        {
            q.push({{node_x_axis - 1, node_y_axis + 1}, curr_node->left});
        }
        // if right child exists, push it into the queue
        if (curr_node->right)
        {
            q.push({{node_x_axis + 1, node_y_axis + 1}, curr_node->right});
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
    vector<int> ans = verticalOrder(root);
    printArray_1D(ans);
}