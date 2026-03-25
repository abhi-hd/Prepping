/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Be careful about graph and indegree : graph[pre[1]].push_back(pre[0]), indegree[pre[0]]++;
for checking 0 indegree, loop runs on numCourses, not on indegree map
*/
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        int done = 0, curr;
        for (vector<int> pre : prerequisites)
            graph[pre[1]].push_back(pre[0]), indegree[pre[0]]++;
        queue<int> buffer;

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                buffer.push(i);

        while (!buffer.empty())
        {
            done++;
            curr = buffer.front();
            buffer.pop();

            for (int i = 0; i < graph[curr].size(); i++)
            {
                if (--indegree[graph[curr][i]] == 0)
                    buffer.push(graph[curr][i]);
            }
        }
        return done == numCourses;
    }
};