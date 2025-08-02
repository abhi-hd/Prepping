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
 199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
 */
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;
        queue<TreeNode *> buffer;
        buffer.push(root);
        while (!buffer.empty())
        {
            int n = buffer.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = buffer.front();
                buffer.pop();
                if (temp->left)
                    buffer.push(temp->left);
                if (temp->right)
                    buffer.push(temp->right);
                if (i == n - 1)
                    result.push_back(temp->val);
            }
        }
        return result;
    }
};