/*
You are given an integer array nums of length n and an integer k.

An element in nums is said to be qualified if there exist at least k elements in the array that are strictly greater than it.

Return an integer denoting the total number of qualified elements in nums.



Example 1:

Input: nums = [3,1,2], k = 1

Output: 2

Explanation:

The elements 1 and 2 each have at least k = 1 element greater than themselves.
​​​​​​​No element is greater than 3. Therefore, the answer is 2.

Example 2:

Input: nums = [5,5,5], k = 2

Output: 0

Explanation:

Since all elements are equal to 5, no element is greater than the other. Therefore, the answer is 0.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countElements(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), result = 0;
        if (k == 0)
            return n;
        for (int i = 0; i < n - 1; i++)
        {
            int count = 1;
            while (nums[i] == nums[i + 1])
            {
                count++;
                i++;
            }
            if (n - 1 - i >= k)
                result += count;
        }
        return result;
    }
};