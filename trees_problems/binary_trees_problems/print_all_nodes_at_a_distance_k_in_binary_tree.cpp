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
void markParent(TreeNode *root, TreeNode *target, map<TreeNode *, TreeNode *> &parent_track_map)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (q.size() > 0)
    {
        int size_of_queue = q.size();
        for (int i = 0; i < size_of_queue; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            // if it's left child exists push it inside the queue and mark it's parent in the map
            if (node->left)
            {
                parent_track_map[node->left] = node;
                q.push(node->left);
            }
            // if it's right child exists push it inside the queue and mark it's parent
            if (node->right)
            {
                parent_track_map[node->right] = node;
                q.push(node->right);
            }
        }
    }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> ans;
    if (root == NULL)
    {
        return {};
    }
    // We will use a map to track node and it's parent correspondingly
    map<TreeNode *, TreeNode *> parent_track_map;
    markParent(root, target, parent_track_map);

    // Create another map to keep track of visited nodes
    map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;

    int curr_level = 0;
    while (q.size() > 0)
    {
        int size_of_queue = q.size();
        if (curr_level == k)
        {
            break;
        }
        curr_level++;
        for (int i = 0; i < size_of_queue; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            // If left child exists and still unvisited, push it inside the queue and mark it visited
            if (node->left != NULL && visited[node->left] == false)
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            // If right child exists and still unvisited, push it inside the queue and mark it visited
            if (node->right != NULL && visited[node->right] == false)
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            // If parent exists of this node and still unvisited, push it inside the queue and mark it visited
            if (parent_track_map[node] != NULL && visited[parent_track_map[node]] == false)
            {
                q.push(parent_track_map[node]);
                visited[parent_track_map[node]] = true;
            }
        }
    }
    while (q.size() != 0)
    {
        ans.push_back(q.front()->val);
        q.pop();
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
    Time complexity: O(2 * N)
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
    vector<int> ans = distanceK(root, node1, 2);
    printArray_1D(ans);
}