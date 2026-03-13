/*
Reverse bits of a given 32 bits signed integer.

Example 1:

Input: n = 43261596

Output: 964176192

Explanation:
Integer	Binary
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000

Example 2:

Input: n = 2147483644

Output: 1073741822

Explanation:
Integer	Binary
2147483644	01111111111111111111111111111100
1073741822	00111111111111111111111111111110
*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Remember uint32_t for unsigned
Other solution
*/
class Solution
{
public:
    int reverseBits(int n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            if (n & 1)
                res |= 1;
            n >>= 1;
        }
        return res;
    }
};