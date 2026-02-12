/*
Given a string s, find the length of the longest

without duplicate characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
*/

#include <bits/stdc++.h>
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0, l = s.size(), lo = 0;
        unordered_map<char, int> frequency;
        for (int i = 0; i < l; i++)
        {
            // better to use frequency than adding and deleting as it takes up extra time
            frequency[s[i]]++;
            while (frequency[s[i]] > 1)
            {
                frequency[s[lo++]]--;
            }
            result = max(i - lo + 1, result);
        }
        return result;
    }
};