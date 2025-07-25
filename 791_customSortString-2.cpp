/*
791. Custom Sort String

You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

Input: order = "cba", s = "abcd"

Output: "cbad"
*/
class Solution
{
public:
    string customSortString(string order, string s)
    {
        map<int, char> priority;
        vector<int> freq(26, 0);
        for (int i = 0; i < order.size(); i++)
            priority[i] = order[i];
        for (auto c : s)
            freq[c - 'a']++;
        string result;
        for (auto &[p, q] : priority)
        {
            while (freq[q - 'a']-- != 0)
                result += q;
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                while (freq[i]-- != 0)
                    result += 'a' + i;
            }
        }
        return result;
    }
};