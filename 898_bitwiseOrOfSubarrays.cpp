/*
898. Bitwise ORs of Subarrays
Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.
Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.
*/
class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        unordered_set<int> result, curr;
        for (auto num : arr)
        {
            unordered_set<int> temp = {num};
            for (auto i : curr)
                temp.insert(i | num);
            curr = temp;
            result.insert(curr.begin(), curr.end());
        }
        return result.size();
    }
};