/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
check stringstream and istringstream syntax
in de-s , you cannot work with only a deque, need queue and array
boundary condition for right node in traversal
*/
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        stringstream ss;
        queue<TreeNode *> buffer;
        buffer.push(root);
        TreeNode *curr;
        while (!buffer.empty())
        {
            curr = buffer.front();
            buffer.pop();
            curr == NULL ? ss << "null#" : ss << to_string(curr->val) + '#';
            if (curr)
            {
                buffer.push(curr->left);
                buffer.push(curr->right);
            }
        }
        cout << ss.str();
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream ss(data);
        string token;
        char delimiter = '#';
        vector<TreeNode *> nodes;
        while (getline(ss, token, delimiter))
        {
            TreeNode *next = NULL;
            if (token != "null")
            {
                next = new TreeNode(stoi(token));
            }
            nodes.push_back(next);
        }
        queue<TreeNode *> buffer;
        buffer.push(nodes[0]);
        int i = 1;
        TreeNode *curr;
        while (!buffer.empty() && i < nodes.size())
        {
            curr = buffer.front();
            buffer.pop();
            curr->left = nodes[i++];
            if (curr->left)
                buffer.push(curr->left);
            if (i < nodes.size())
            {
                curr->right = nodes[i++];
                if (curr->right)
                    buffer.push(curr->right);
            }
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));