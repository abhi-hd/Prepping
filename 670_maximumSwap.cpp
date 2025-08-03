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
        int n = number.size(), currMax = INT_MIN, index = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (number[j] > number[i] && number[j] >= currMax)
                {
                    index = j;
                    currMax = number[j];
                }
            }
            if (index != INT_MIN)
            {
                swap(number[i], number[index]);
                return stoi(number);
            }
        }
        return num;
    }
};