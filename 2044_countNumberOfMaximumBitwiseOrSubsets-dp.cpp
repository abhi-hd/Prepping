/*
2044. Count Number of Maximum Bitwise-OR Subsets
Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).
Input: nums = [3,2,1,5]
Output: 6
Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
*/
class Solution
{
private:
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxOr = 0, n = nums.size();
        for (auto num : nums)
            maxOr |= num;
        vector<vector<int>> memo(n, vector<int>(maxOr + 1, -1));
        return recurse(nums, 0, 0, maxOr, memo);
    }
    int recurse(vector<int> &nums, int start, int currOr, int maxOr, vector<vector<int>> &memo)
    {
        if (start == nums.size())
        {
            return currOr == maxOr ? 1 : 0;
        }
        if (memo[start][currOr] != -1)
            return memo[start][currOr];

        int countWithout = recurse(nums, start + 1, currOr, maxOr, memo);
        int countWith = recurse(nums, start + 1, currOr | nums[start], maxOr, memo);
        return memo[start][currOr] = countWithout + countWith;
    }
};