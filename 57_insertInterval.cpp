/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Binary search is not good since , it can find insertion position, but it's O(n) for merge traversal
Instead of having if else in first while loop, just add codition in the while loop
Above step is also to ensure the newInterval is added if it's the last one i.e ,
    result.push_back(newInterval) should not be in that loop
While adding newInterval also we need to check for mergeability
*/
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        int i = 0, l = intervals.size();
        while (i < l && intervals[i][0] < newInterval[0])
            result.push_back(intervals[i++]);
        if (!result.empty() && result.back()[1] >= newInterval[0])
            result.back()[1] = max(result.back()[1], newInterval[1]);
        else
            result.push_back(newInterval);
        while (i < l)
        {
            if (result.back()[1] >= intervals[i][0])
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            else
                result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};