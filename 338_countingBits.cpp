/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
        {
            result[i] = bits(i);
        }
        return result;
    }
    int bits(int n)
    {
        int result = 0;
        while (n)
        {
            result += n & 1;
            n = n >> 1;
        }
        return result;
    }
};