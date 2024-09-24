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
TreeNode *buildTree(int inOrder[], int preOrder[], int n)
{
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O()
    Space complexity: O()
    */
    int inOrder = {1, 6, 8, 7};
    int preOrder = {1, 6, 7, 8};
    TreeNode *tree = buildTree(inOrder, preOrder, 4);
    
}