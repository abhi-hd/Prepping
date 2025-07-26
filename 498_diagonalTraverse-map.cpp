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
        map<int, vector<int>> store;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                store[i + j].push_back(mat[i][j]);
            }
        }
        for (auto &[val, arr] : store)
        {
            if (val % 2 == 1)
                result.insert(result.end(), arr.begin(), arr.end());
            else
            {
                reverse(arr.begin(), arr.end());
                result.insert(result.end(), arr.begin(), arr.end());
            }
        }
        return result;
    }
};