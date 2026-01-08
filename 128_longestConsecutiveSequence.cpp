/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> store(nums.begin(), nums.end());
        int result = 0;
        for (auto num : nums)
        {
            if (store.find(num) == store.end() || store.find(num - 1) != store.end())
                continue;
            int next = num + 1;
            store.erase(num);
            while (store.find(next) != store.end())
            {
                store.erase(next);
                next++;
            }
            result = max(result, next - num);
        }
        return result;
    }
};