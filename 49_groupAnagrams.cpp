/*
Given an array of strings strs, group the together. You can return the answer in any order.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

*/

#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Can be further optimized by using counting sort as limited alphabet
*/
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> store;
        string curr;
        for (string s : strs)
        {
            curr = s;
            sort(curr.begin(), curr.end());
            store[curr].push_back(s);
        }
        vector<vector<string>> result;
        for (pair<string, vector<string>> p : store)
            result.push_back(p.second);
        return result;
    }
};