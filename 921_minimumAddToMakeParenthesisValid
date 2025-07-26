/*
921. Minimum Add to Make Parentheses Valid
A parentheses string is valid if and only if:

    It is the empty string,
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

    For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".

Return the minimum number of moves required to make s valid.
Input: s = "((("
Output: 3
*/
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int curr = 0, left = 0;
        for (auto c : s)
        {
            if (c == '(')
                curr++;
            if (c == ')')
            {
                if (curr > 0)
                    curr--;
                else
                {
                    left++;
                }
            }
        }
        return left + curr;
    }
};