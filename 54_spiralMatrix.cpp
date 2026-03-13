/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
take boundaries l, r, u, d
remember u != d and l != r for 3rd and 4th stages
think very carefully about matrix indices
remember i != u in the last loop
*/
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), l = 0, r = m - 1, u = 0, d = n - 1;
        vector<int> result;
        while (l <= r && u <= d)
        {
            for (int i = l; i <= r; i++)
                result.push_back(matrix[u][i]);
            for (int i = u + 1; i <= d; i++)
                result.push_back(matrix[i][r]);
            if (u != d)
                for (int i = r - 1; i >= l; i--)
                    result.push_back(matrix[d][i]);
            if (l != r)
                for (int i = d - 1; i > u; i--)
                    result.push_back(matrix[i][l]);
            l++, r--, u++, d--;
        }
        return result;
    }
};