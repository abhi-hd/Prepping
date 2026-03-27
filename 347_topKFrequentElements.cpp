/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct comparator
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, comparator> heap;
        unordered_map<int, int> freqStore;
        for (auto num : nums)
            freqStore[num]++;
        vector<int> result;
        for (auto p : freqStore)
            heap.push({p.first, p.second});
        for (int i = 0; i < k; i++)
        {
            result.push_back(heap.top()[0]);
            heap.pop();
        }
        return result;
    }
};