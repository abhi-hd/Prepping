/*
Given an integer array nums, return the length of the longest strictly increasing .

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Remember you don't have to store the value in a pair, can access by index
remember the equality while checking previous values, otherwise the if condition will never trigger
*/
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), result = 1;
        vector<int> store(n, 1);
        for (int i = 1; i < n; i++)
        {
            int curr = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && store[i] <= store[j])
                {
                    store[i] = store[j] + 1;
                }
            }
            result = max(result, store[i]);
        }
        return result;
    }
};