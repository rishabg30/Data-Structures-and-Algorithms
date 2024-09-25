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
TreeNode *myTree(int inOrder[], int postOrder[], int inOrderStart, int inOrderEnd, int index)
{
    // Terminating condition
    if (inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    // Step 1-> Create a root node from postOrder array
    TreeNode *root = new TreeNode(postOrder[index]);
    // Step 2-> Find out the position of root node in inOrder array
    int position = findPosition(root->val, inOrder, inOrderStart, inOrderEnd);

    // For postOrder, we have to first go to the right side and buildTree and then to the left side
    // Build right tree
    root->right = myTree(inOrder, postOrder, position + 1, inOrderEnd, index - 1);
    // Build left tree
    root->left = myTree(inOrder, postOrder, inOrderStart, position - 1, index - (inOrderEnd - position) - 1);

    return root;
}
TreeNode *buildTree(int n, int inOrder[], int postOrder[])
{
    // Here index will start from reverse order
    return myTree(inOrder, postOrder, 0, n - 1, n - 1);
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
    int inOrder[5] = {9, 5, 2, 3, 4};
    int postOrder[5] = {5, 9, 3, 4, 2};
    TreeNode *root = buildTree(5, inOrder, postOrder);
}