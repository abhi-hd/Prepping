/*
398. Random Pick Index
Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Implement the Solution class:

    Solution(int[] nums) Initializes the object with the array nums.
    int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.
Input
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output
[null, 4, 0, 2]
*/
class Solution
{
private:
    vector<int> nums;

public:
    Solution(vector<int> &nums)
    {
        this->nums.swap(nums);
    }

    int pick(int target)
    {
        int n = nums.size(), count = 0, idx = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                count++;
                if (rand() % count == 0)
                {
                    idx = i;
                }
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */