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
vector<int> rightView(TreeNode *root)
{
    vector<int> ans;
    // Right view: Level order traversal last node is always right view.
    if (root == NULL)
    {
        return {};
    }

    queue<TreeNode *> q;
    q.push(root);

    while (q.size() > 0)
    {
        int size_of_queue = q.size();
        int right_candidate = INT_MIN;
        for (int i = 0; i < size_of_queue; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            right_candidate = node->val;

            // if left child exists push it in the queue
            if (node->left)
            {
                q.push(node->left);
            }
            // if right child exists push it in the queue
            if (node->right)
            {
                q.push(node->right);
            }
        }
        ans.push_back(right_candidate);
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
    vector<int> ans = rightView(root);
    printArray_1D(ans);
}