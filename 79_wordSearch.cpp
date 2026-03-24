/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


*/

#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Instead of taking a bool and doing result = result || check(...) , justr use if(check(...))
weird backtracking for visited array, makes sense but weird
be careful about order of if statements in check
*/
class Solution
{
public:
    vector<vector<int>> visited;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n, m;
    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size(), m = board[0].size();
        visited.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (check(board, word, i, j, 0))
                    return true;
        }
        return false;
    }
    bool check(vector<vector<char>> &board, string word, int x, int y, int w)
    {
        if (word[w] != board[x][y])
            return false;
        if (visited[x][y] == 1)
            return false;
        if (w == word.size() - 1)
            return true;

        visited[x][y] = 1;
        bool result = false;
        int newx, newy;
        for (int i = 0; i < dirs.size(); i++)
        {
            newx = x + dirs[i][0];
            newy = y + dirs[i][1];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && check(board, word, newx, newy, w + 1))
                return true;
        }
        visited[x][y] = 0;
        return false;
    }
};