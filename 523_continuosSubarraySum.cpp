/*
523. Continuous Subarray Sum
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

    its length is at least two, and
    the sum of the elements of the subarray is a multiple of k.

Note that:

    A subarray is a contiguous part of the array.
    An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

*/
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        unordered_map<int, int> reminders;
        reminders[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            sum %= k;
            if (reminders.count(sum))
            {
                if (i - reminders[sum] >= 2)
                    return true;
            }
            else
            {
                reminders[sum] = i;
            }
        }
        return false;
    }
};