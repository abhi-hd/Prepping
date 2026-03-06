/*
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.

Example 2:

Input: s = "110"
Output: true
*/

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int i = 0;
        while (i < s.size() && s[i] == '1')
            i++;
        for (i; i < s.size(); i++)
        {
            if (s[i] == '1')
                return false;
        }
        return true;
    }
};