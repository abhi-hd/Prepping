/*
Given a string s, calculate its reverse degree.

The reverse degree is calculated as follows:

    For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
    Sum these products for all characters in the string.

Return the reverse degree of s.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverseDegree(string s)
    {
        int result = 0, l = s.size();
        for (int i = 0; i < l; i++)
        {
            result += (26 - (int)(s[i] - 'a')) * (i + 1);
        }
        return result;
    }
};