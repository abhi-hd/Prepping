/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.

*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
divide lo -> mid, mid+1 -> hi (mid needs to be included on some side)
remember to run loop for both arrays indivdually when comparision loop is done in merge step
*/
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergesort(vector<int> &nums, int lo, int hi)
    {
        if (lo >= hi)
            return;
        int mid = lo + (hi - lo) / 2;
        mergesort(nums, lo, mid);
        mergesort(nums, mid + 1, hi);
        merge(nums, lo, hi, mid);
    }
    void merge(vector<int> &nums, int lo, int hi, int mid)
    {
        vector<int> temp(hi - lo + 1);
        int i = lo, j = mid + 1, k = 0;

        while (i <= mid && j <= hi)
        {
            if (nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= hi)
            temp[k++] = nums[j++];

        for (i = 0; i < hi - lo + 1; i++)
            nums[lo + i] = temp[i];
    }
};