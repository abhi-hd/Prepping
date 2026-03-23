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
take random pivot -> put pivot to end of range -> put all elements before if < pivot -> swap pivot and end of range -> return pivot index
divide both sides, lo -> pivot-1 , pivot+1 -> hi
*/
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quicksort(vector<int> &nums, int lo, int hi)
    {
        if (lo >= hi)
            return;
        int pivot = partition(nums, lo, hi);
        quicksort(nums, lo, pivot - 1);
        quicksort(nums, pivot + 1, hi);
    }
    int partition(vector<int> &nums, int lo, int hi)
    {
        int pivot = lo + rand() % (hi - lo);
        swap(nums[pivot], nums[hi]);
        int index = lo;
        for (int i = lo; i < hi; i++)
        {
            if (nums[i] < nums[hi])
                swap(nums[i], nums[index++]);
        }
        swap(nums[index], nums[hi]);
        return index;
    }
};