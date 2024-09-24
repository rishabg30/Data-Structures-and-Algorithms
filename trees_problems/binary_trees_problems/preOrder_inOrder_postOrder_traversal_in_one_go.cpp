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
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    vector<int> preOrder, inOrder, postOrder;
    // as during recursion calls are stored in stack, therefore we will use stack data structure
    if (root == NULL)
    {
        return {{}};
    }
    // preOrder traversal : Node, Left, Right
    // inOrder traversal : Left, Node, Right
    // postOrder traversal : Left, Right, Node

    // stack will store {node, number_of_time_it_is_visited}
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (st.size() > 0)
    {
        TreeNode *node = st.top().first;
        int number = st.top().second;
        st.pop();

        // if number is 1, it means preOrder traversal
        // store it in preOrder ans vector, increase the number by 1 and move to left child if exists
        if (number == 1)
        {
            preOrder.push_back(node->val);
            number++;
            st.push({node, number});
            if (node->left)
            {
                st.push({node->left, 1});
            }
        }
        // if number is 2, it means inOrder traversal
        // store it in inOrder ans vector, increase the number by 1 and move to right child if it exists
        else if (number == 2)
        {
            inOrder.push_back(node->val);
            number++;
            st.push({node, number});
            if (node->right)
            {
                st.push({node->right, 1});
            }
        }
        // if number is 3, it means postOrder traversal
        // store it in postOrder ans vector and continue
        else
        {
            postOrder.push_back(node->val);
        }
    }
    ans.push_back(preOrder);
    ans.push_back(inOrder);
    ans.push_back(postOrder);
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
    vector<vector<int>> ans = getTreeTraversal(root);
    printArray_2D(ans);
}