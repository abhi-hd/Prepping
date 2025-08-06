/*
766. Toeplitz Matrix
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
*/
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        unordered_map<int, int> store;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (store.count(i - j))
                {
                    if (store[i - j] != matrix[i][j])
                        return false;
                }
                else
                {
                    store[i - j] = matrix[i][j];
                }
            }
        }
        return true;
    }
};