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
        if (!head)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next)
            slow = slow->next;

        ListNode *first = NULL, *second = slow->next, *third, *reversed;
        slow->next = NULL;
        while (second != NULL)
        {
            third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
        reversed = first;

        ListNode *first1 = head, *second1 = reversed, *first2, *second2;
        while (second1)
        {
            first2 = first1->next;
            second2 = second1->next;
            first1->next = second1;
            second1->next = first2;
            first1 = first2;
            second1 = second2;
        }
    }
};