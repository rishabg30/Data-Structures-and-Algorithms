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
int findPosition(int target, int inOrder[], int inOrderStart, int inOrderEnd)
{
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (inOrder[i] == target)
        {
            return i;
        }
    }
    return -1;
}
TreeNode *myTree(int inOrder[], int preOrder[], int inOrderStart, int inOrderEnd, int index)
{
    // Terminating condition
    if (inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    // Step 1-> Create a root node from preOrder array
    TreeNode *root = new TreeNode(preOrder[index]);
    // Step 2-> Find out the position of root node in inOrder array
    int position = findPosition(root->val, inOrder, inOrderStart, inOrderEnd);

    // Build left tree
    root->left = myTree(inOrder, preOrder, inOrderStart, position - 1, index + 1);
    // Build right tree
    root->right = myTree(inOrder, preOrder, position + 1, inOrderEnd, index + (position - inOrderStart) + 1);
    return root;
}
TreeNode *buildTree(int inOrder[], int preOrder[], int n)
{
    return myTree(inOrder, preOrder, 0, n - 1, 0);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N * N)
    Space complexity: O(N)
    */
    int inOrder[4] = {1, 6, 8, 7};
    int preOrder[4] = {1, 6, 7, 8};
    TreeNode *tree = buildTree(inOrder, preOrder, 4);
}