/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
+ -*-,
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *first = head, *second = head->next, *third;
        first->next = NULL;
        while (second != NULL)
        {
            third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
        return first;
    }
};