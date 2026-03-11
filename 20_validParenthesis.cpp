/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

*/

#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
The parenthesis should match too i.e ([)] is not valid
*/
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> store;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                store.push(c);
            else
            {
                switch (c)
                {
                case ')':
                    if (store.empty() || store.top() != '(')
                        return false;
                    store.pop();
                    break;
                case '}':
                    if (store.empty() || store.top() != '{')
                        return false;
                    store.pop();
                    break;
                case ']':
                    if (store.empty() || store.top() != '[')
                        return false;
                    store.pop();
                    break;
                }
            }
        }
        return store.size() == 0;
    }
};