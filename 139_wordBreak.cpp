/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_set<string> store;
    vector<int> precheck;
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (string word : wordDict)
            store.insert(word);
        precheck.resize(s.size(), -1);
        return possible(0, s);
    }
    bool possible(int start, const string &s)
    {
        int l = s.size();
        if (start == l)
            return true;
        if (precheck[start] != -1)
            return precheck[start] == 1;
        bool result = false;
        for (int i = start + 1; i <= l; i++)
        {
            if (store.find(s.substr(start, i - start)) != store.end())
            {
                result = result || possible(i, s);
            }
        }
        if (result == true)
            precheck[start] = 1;
        else
            precheck[start] = 0;
        return result;
    }
};