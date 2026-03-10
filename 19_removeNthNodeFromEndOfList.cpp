/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int i = 0;
        ListNode *curr = head, *nth = head, *prev;
        while (i < n)
        {
            i++;
            nth = nth->next;
        }
        while (nth)
        {
            nth = nth->next;
            prev = curr;
            curr = curr->next;
        }
        if (curr == head)
            return head->next;
        prev->next = curr->next;
        return head;
    }
};