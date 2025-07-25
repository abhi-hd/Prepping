/*
1091. Shortest Path in Binary Matrix
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
*/
class Solution
{
private:
    unordered_set<int> visited;
    queue<vector<int>> buffer;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {1, 1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {-1, -1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        buffer.push({0, 0, 1});
        visited.insert(0);
        while (!buffer.empty())
        {
            vector<int> current = buffer.front();
            if (current[0] == n - 1 && current[1] == m - 1)
                return current[2];
            buffer.pop();

            for (int i = 0; i < dirs.size(); i++)
            {
                int x = current[0] + dirs[i][0], y = current[1] + dirs[i][1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && !visited.count(101 * x + y))
                {
                    if (x == n - 1 && y == m - 1)
                        return current[2] + 1;
                    buffer.push({x, y, current[2] + 1});
                    visited.insert(101 * x + y);
                }
            }
        }
        return -1;
    }
};