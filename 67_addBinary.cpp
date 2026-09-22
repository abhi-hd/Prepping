/*Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Just work out the indices better
*/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        int al = a.size(), bl = b.size(), carry = 0, sum = 0;
        while (al > 0 || bl > 0 || carry)
        {
            sum = 0;
            if (al)
                sum += a[--al] - '0';
            if (bl)
                sum += b[--bl] - '0';
            if (carry)
                sum += 1;
            result.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};