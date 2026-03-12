/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Instead of running a loop for all alphabets, try frequency method
For sliding window, always remember to make hi as for loop, cleaner, less bugs
*/
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int result = 0, lo = 0, maxfreq = 0;
        vector<int> freq(26, 0);

        for (int hi = 0; hi < s.size(); hi++)
        {
            freq[s[hi] - 'A']++;
            maxfreq = max(maxfreq, freq[s[hi] - 'A']);

            if (hi - lo + 1 - maxfreq > k)
            {
                freq[s[lo++] - 'A']--;
            }

            result = max(hi - lo + 1, result);
        }
        return result;
    }
};