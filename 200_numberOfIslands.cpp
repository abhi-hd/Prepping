/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
remember value is char
*/
class Solution
{
public:
    int result, n, m;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>> &grid)
    {
        result = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    recurse(grid, i, j);
                }
            }
        }
        return result;
    }
    void recurse(vector<vector<char>> &grid, int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1')
            return;

        grid[x][y] = '0';
        int newx, newy;
        for (int i = 0; i < dirs.size(); i++)
        {
            newx = x + dirs[i][0];
            newy = y + dirs[i][1];
            recurse(grid, newx, newy);
        }
    }
};