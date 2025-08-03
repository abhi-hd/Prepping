/*
670. Maximum Swap
You are given an integer num. You can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
*/
class Solution
{
public:
    int maximumSwap(int num)
    {
        string number = to_string(num);
        int lefti = -1, righti = -1, maxi = -1, n = number.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (maxi == -1 || number[i] > number[maxi])
            {
                maxi = i;
            }
            else if (number[i] < number[maxi])
            {
                righti = maxi;
                lefti = i;
            }
        }
        if (lefti != -1 && righti != -1)
        {
            swap(number[lefti], number[righti]);
        }
        return stoi(number);
    }
};