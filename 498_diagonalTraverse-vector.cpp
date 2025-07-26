/*
498. Diagonal Traverse
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
*/
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> result;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> store(n + m - 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                store[i + j].push_back(mat[i][j]);
            }
        }
        int r = store.size();
        for (int i = 0; i < r; i++)
        {
            if (i % 2 == 1)
                result.insert(result.end(), store[i].begin(), store[i].end());
            else
            {
                reverse(store[i].begin(), store[i].end());
                result.insert(result.end(), store[i].begin(), store[i].end());
            }
        }
        return result;
    }
};