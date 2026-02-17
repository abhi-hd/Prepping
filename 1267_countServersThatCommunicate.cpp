/*
1267. Count Servers that Communicate

You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

Example 3:
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
*/
class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), count = 0, isolated = 0;
        unordered_map<int, vector<int>> rows, columns;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                    rows[i].push_back(j);
                    columns[j].push_back(i);
                }
            }
        }
        for (auto v : rows)
        {
            if (v.second.size() == 1)
            {
                if (columns[v.second[0]].size() == 1)
                {
                    isolated++;
                }
            }
        }
        return count - isolated;
    }
};