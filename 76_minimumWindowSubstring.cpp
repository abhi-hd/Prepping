/*
Given two strings s and t of lengths m and n respectively, return the minimum window of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
(IMP) https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solv-lct0/
*/
class Solution
{
public:
    string minWindow(string s, string t)
    {
        string result;
        unordered_map<char, int> store;

        int m = s.size(), lo = 0, rem = 0;
        for (char c : t)
            store[c]++, rem++;
        for (int hi = 0; hi < m; hi++)
        {
            if (store[s[hi]]-- > 0)
                rem--;
            if (rem == 0)
            {
                while (lo < hi && store[s[lo]] < 0)
                    store[s[lo++]]++;
                if (result.empty() || result.size() > hi - lo + 1)
                    result = s.substr(lo, hi - lo + 1);
            }
        }
        return result;
    }
};