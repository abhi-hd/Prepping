/*
827. Making A Large Island
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
*/
class Solution
{
private:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    unordered_map<int, int> sizes;
    int n, m, biggestIsland;

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size(), biggestIsland = 0;
        int number = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    number++;
                    traverse(grid, i, j, number);
                }
            }
        }
        int result = biggestIsland;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    int sum = 0;
                    unordered_set<int> islands;
                    for (int k = 0; k < 4; k++)
                    {
                        int in = i + dirs[k][0], jn = j + dirs[k][1];
                        if (isValid(in, jn) && grid[in][jn] != 0)
                        {
                            islands.insert(grid[in][jn]);
                        }
                    }
                    for (auto is : islands)
                        sum += sizes[is];
                    result = max(result, sum + 1);
                }
            }
        }
        return result;
    }
    void traverse(vector<vector<int>> &grid, int x, int y, int number)
    {
        queue<pair<int, int>> buffer;
        buffer.push({x, y});
        grid[x][y] = number;
        while (!buffer.empty())
        {
            sizes[number]++;
            biggestIsland = max(biggestIsland, sizes[number]);
            pair<int, int> front = buffer.front();
            buffer.pop();
            for (int i = 0; i < 4; i++)
            {
                int xn = front.first + dirs[i][0], yn = front.second + dirs[i][1];
                if (isValid(xn, yn) && grid[xn][yn] == 1)
                {
                    grid[xn][yn] = number;
                    buffer.push({xn, yn});
                }
            }
        }
    }
    bool isValid(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};