/*
1249. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
*/
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> store;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                store.push(i);
            else if (s[i] == ')')
            {
                if (store.empty())
                    s[i] = '#';
                else
                    store.pop();
            }
        }
        while (!store.empty())
        {
            s[store.top()] = '#';
            store.pop();
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};