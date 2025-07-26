/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
/*
109. Convert Sorted List to Binary Search Tree
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a binary search tree.
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
*/
class Solution
{
public:
    ListNode *itr;
    // int count = 0;
    int size(ListNode *head)
    {
        int res = 0;
        while (head != NULL)
        {
            res++;
            head = head->next;
        }
        return res;
    }
    TreeNode *toBST(int l, int r)
    {
        // cout<< "count "<< count++ << endl;
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;
        // cout << mid << " l " << l << " r " << r << endl;
        TreeNode *left = toBST(l, mid - 1);

        TreeNode *root = new TreeNode(itr->val);
        // cout<< "root " << root->val << endl;

        root->left = left;
        // if(root->left != NULL) cout << "left " << root->left->val <<endl;
        itr = itr->next;

        root->right = toBST(mid + 1, r);
        // if(root->right != NULL) cout << "right " <<  root->right->val << endl;
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        int n = size(head);
        itr = head;
        return toBST(0, n - 1);
    }
};