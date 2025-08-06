/*
1340. Jump Game V
Given an array of integers arr and an integer d. In one step you can jump from index i to index:

    i + x where: i + x < arr.length and  0 < x <= d.
    i - x where: i - x >= 0 and  0 < x <= d.

In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.
Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
*/
class Solution
{
private:
    vector<int> dp;
    int n;

public:
    int maxJumps(vector<int> &arr, int d)
    {
        n = arr.size();
        dp.resize(n, -1);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = max(result, calculate(arr, i, d));
        }
        return result;
    }
    int calculate(vector<int> &arr, int index, int d)
    {
        if (!isValid(index))
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int answer = 1;
        for (int i = index + 1; i <= index + d; i++)
        {
            if (isValid(i))
            {
                if (arr[i] >= arr[index])
                    break;
                answer = max(answer, 1 + calculate(arr, i, d));
            }
        }
        for (int i = index - 1; i >= index - d; i--)
        {
            if (isValid(i))
            {
                if (arr[i] >= arr[index])
                    break;
                answer = max(answer, 1 + calculate(arr, i, d));
            }
        }
        return dp[index] = answer;
    }
    bool isValid(int index)
    {
        return index >= 0 && index < n;
    }
};