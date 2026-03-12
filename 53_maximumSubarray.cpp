/*
Given an integer array nums, find the with the largest sum, and return its sum.
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
The intuition is when two overlap, one has to be removed, keep the interval with the least end time
prev is always i if not replaced, otherwise it's the smallest end time
*/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr = 0, l = nums.size(), result = INT_MIN;
        for (int i = 0; i < l; i++)
        {
            curr += nums[i];
            result = max(curr, result);
            if (curr <= 0)
                curr = 0;
        }
        return result;
    }
};