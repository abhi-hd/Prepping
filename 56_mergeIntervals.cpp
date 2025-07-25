/*
56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (auto interval : intervals)
        {
            if (result.empty() || result.back()[1] < interval[0])
            {
                result.push_back(interval);
            }
            else
            {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};