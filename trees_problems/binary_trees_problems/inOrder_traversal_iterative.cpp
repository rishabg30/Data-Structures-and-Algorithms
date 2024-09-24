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
vector<int> inOrder(TreeNode *root)
{
    vector<int> ans;
    // as during recursion calls are stored in stack, therefore we will use stack data structure
    if (root == NULL)
    {
        return {};
    }
    // inOrder traversal : Left, Node, Right
    stack<TreeNode *> st;
    TreeNode *node = root;

    while (true)
    {
        // Push left node in the stack until left child is present
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            // If stack becomes empty return
            if (st.size() == 0)
            {
                break;
            }
            // else now left child is over, pop it and store in answer vector and move to right child
            else
            {
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
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
    vector<int> ans = inOrder(root);
    printArray_1D(ans);
}