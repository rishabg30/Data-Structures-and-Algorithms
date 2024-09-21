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
    int x, first, second;
    cin >> x;
    cout << "Enter the root node: " << x << endl;

    queue<TreeNode *> q;
    q.push(new TreeNode(x));

    while (!q.empty())
    {
        // Pop out the front node
        TreeNode *node = q.front();
        q.pop();

        // Adding it's left child
        cin >> first;
        cout << "Enter the left child of " << node->val << ": " << first << endl;

        if (first != -1)
        {
            node->left = new TreeNode(first);
            q.push(node->left);
        }
        // Adding it's right child
        cin >> second;
        cout << "Enter the right child of " << node->val << ": " << second << endl;
        if (second != -1)
        {
            node->right = new TreeNode(second);
            q.push(node->right);
        }
    }
}