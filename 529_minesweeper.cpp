/*
529. Minesweeper
You are given an m x n char matrix board representing the game board where:

    'M' represents an unrevealed mine,
    'E' represents an unrevealed empty square,
    'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
    digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
    'X' represents a revealed mine.

You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

Return the board after revealing this position according to the following rules:

    If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
    If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
    If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
    Return the board when no more squares will be revealed.
Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
*/
class Solution
{
private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int n, m;

public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        n = board.size(), m = board[0].size();
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
        }
        if (board[click[0]][click[1]] == 'E')
        {
            dfs(board, click);
        }
        return board;
    }
    void dfs(vector<vector<char>> &board, vector<int> &click)
    {
        if (!isValid(click) || board[click[0]][click[1]] != 'E')
            return;
        int mines = 0;
        vector<vector<int>> nextPos = nextPositions(click);
        for (auto next : nextPos)
        {
            if (board[next[0]][next[1]] == 'M')
                mines++;
        }
        if (mines == 0)
        {
            board[click[0]][click[1]] = 'B';
            for (auto next : nextPos)
            {
                dfs(board, next);
            }
        }
        else
        {
            board[click[0]][click[1]] = '0' + mines;
        }
    }
    bool isValid(vector<int> &p)
    {
        return p[0] >= 0 && p[0] < n && p[1] >= 0 && p[1] < m;
    }
    vector<vector<int>> nextPositions(vector<int> &p)
    {
        vector<vector<int>> result;
        for (auto dir : dirs)
        {
            vector<int> next = {p[0] + dir[0], p[1] + dir[1]};
            if (isValid(next))
            {
                result.push_back({p[0] + dir[0], p[1] + dir[1]});
            }
        }
        return result;
    }
};