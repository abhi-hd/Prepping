/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

*/

#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
take two visited arrays, instead of state of visited as 0,1,2,3
careful with start of dfs , 0, i , j, n-1, m-1 boundaries
check if newx and new y are within bounds
*/
class Solution
{
public:
    vector<vector<bool>> atlantic, pacific;
    vector<vector<int>> result;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        if (!heights.size())
            return result;
        n = heights.size(), m = heights[0].size();
        atlantic.resize(n, vector<bool>(m, false));
        pacific.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m - 1);
        }
        for (int j = 0; j < m; j++)
        {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, n - 1, j);
        }
        return result;
    }
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int x, int y)
    {
        if (visited[x][y])
            return;
        visited[x][y] = true;

        if (atlantic[x][y] && pacific[x][y])
            result.push_back({x, y});

        for (int i = 0; i < dirs.size(); i++)
        {
            int newx = x + dirs[i][0], newy = y + dirs[i][1];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && heights[newx][newy] >= heights[x][y])
            {
                dfs(heights, visited, newx, newy);
            }
        }
    }
};