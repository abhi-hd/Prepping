/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
987. Vertical Order Traversal of a Binary Tree
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
*/
class Solution
{
private:
    struct comparator
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        }
    };

public:
    unordered_map<int, vector<vector<int>>> store;
    int maxLeft, maxRight;
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        maxLeft = 0, maxRight = 0;
        traverse(root, 0, 0);
        vector<vector<int>> result;
        for (int i = maxLeft; i <= maxRight; i++)
        {
            sort(store[i].begin(), store[i].end(), comparator());
            vector<int> temp;
            for (auto v : store[i])
                temp.push_back(v[0]);
            result.push_back(temp);
        }
        return result;
    }
    void traverse(TreeNode *root, int col, int row)
    {
        if (!root)
            return;
        maxLeft = min(maxLeft, col);
        maxRight = max(maxRight, col);
        store[col].push_back({root->val, row});
        traverse(root->left, col - 1, row + 1);
        traverse(root->right, col + 1, row + 1);
    }
};