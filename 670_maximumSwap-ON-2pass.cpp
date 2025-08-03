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
        int n = number.size();
        vector<int> rightIndex(n, -1);
        rightIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            rightIndex[i] = number[i] > number[rightIndex[i + 1]] ? i : rightIndex[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            if (number[i] < number[rightIndex[i]])
            {
                swap(number[i], number[rightIndex[i]]);
                return stoi(number);
            }
        }
        return num;
    }
};