/*
689. Maximum Sum of 3 Non-Overlapping Subarrays
Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
*/
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> cumulative(n + 1, 0);
        for (int i = 0; i < n; i++)
            cumulative[i + 1] = cumulative[i] + nums[i];

        vector<vector<int>> bestSum(4, vector<int>(n + 1, 0));
        vector<vector<int>> bestIndex(4, vector<int>(n + 1, 0));

        for (int subarrayCount = 1; subarrayCount <= 3; subarrayCount++)
        {
            for (int endIndex = k * subarrayCount; endIndex <= n; endIndex++)
            {
                int currentSum = cumulative[endIndex] - cumulative[endIndex - k] +
                                 bestSum[subarrayCount - 1][endIndex - k];
                if (currentSum > bestSum[subarrayCount][endIndex - 1])
                {
                    bestSum[subarrayCount][endIndex] = currentSum;
                    bestIndex[subarrayCount][endIndex] = endIndex - k;
                }
                else
                {
                    bestSum[subarrayCount][endIndex] = bestSum[subarrayCount][endIndex - 1];
                    bestIndex[subarrayCount][endIndex] = bestIndex[subarrayCount][endIndex - 1];
                }
            }
        }
        vector<int> result(3, 0);
        int currentEnd = n;
        for (int subarrayIndex = 3; subarrayIndex >= 1; subarrayIndex--)
        {
            result[subarrayIndex - 1] = bestIndex[subarrayIndex][currentEnd];
            currentEnd = result[subarrayIndex - 1];
        }
        return result;
    }
};