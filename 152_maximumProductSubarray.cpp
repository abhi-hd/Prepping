/*
Given an integer array nums, find a that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = 1, mini = 1, result = INT_MIN, temp;
        for (auto num : nums)
        {
            temp = maxi;
            maxi = max({num, maxi * num, mini * num});
            mini = min({num, temp * num, mini * num});
            result = max(result, maxi);
        }
        return result;
    }
};