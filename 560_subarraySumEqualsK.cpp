/*
560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
-1000 <= nums[i] <= 1000
*/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> sums;
        sums[0]++;
        int currSum = 0, result = 0;
        for (auto num : nums)
        {
            currSum += num;
            result += sums[currSum - k];
            sums[currSum]++;
        }
        return result;
    }
};