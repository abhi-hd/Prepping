/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;

        stack<ListNode *> store;
        ListNode *itr = head;
        while (itr)
        {
            store.push(itr);
            itr = itr->next;
        }
        ListNode *temp, *curr = head, *top;
        int l = store.size();
        for (int i = 0; i < l / 2; i++)
        {
            temp = curr->next;
            top = store.top();
            store.pop();
            curr->next = top;
            top->next = temp;
            curr = temp;
        }
        temp->next = NULL;
    }
};