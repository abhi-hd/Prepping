/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Example 1:

Input: nums = [3,2,3]
Output: [3]

Example 2:

Input: nums = [1]
Output: [1]

Example 3:

Input: nums = [1,2]
Output: [1,2]

*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
TODO: space optimization for O(1) space using Boyer-Moore majority voting
*/
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size(), limit = n / 3;
        unordered_map<int, int> freqStore;
        vector<int> result;
        for (int num : nums)
            freqStore[num]++;
        for (auto p : freqStore)
            if (p.second > limit)
                result.push_back(p.first);
        return result;
    }
};