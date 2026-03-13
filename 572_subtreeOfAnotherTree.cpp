/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
*/

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
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
think about it like , the outer function recurses over the tree and at each point we check if they the same subtree
Pay attention to the isSubtree func, isSame is simple
*/
class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return subRoot == NULL;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) || isSame(root, subRoot);
    }
    bool isSame(TreeNode *one, TreeNode *two)
    {
        if (!one && !two)
            return true;
        else if (!one || !two)
            return false;
        if (one->val != two->val)
            return false;
        return isSame(one->left, two->left) && isSame(one->right, two->right);
    }
};