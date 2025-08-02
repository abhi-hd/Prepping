/*
2561. Rearranging Fruits
You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

    Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
    The cost of the swap is min(basket1[i],basket2[j]).

Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.

Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
*/
class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        map<int, int> count;
        for (auto num : basket1)
            count[num]++;
        for (auto num : basket2)
            count[num]--;
        vector<long long> swaps;
        long long result = 0, minEl = count.begin()->first;
        for (auto &[k, v] : count)
        {
            if (v % 2)
                return -1;
            for (int i = 0; i < abs(v) / 2; i++)
                swaps.push_back(k);
        }
        for (int i = 0; i < swaps.size() / 2; i++)
        {
            result += min(swaps[i], 2 * minEl);
        }
        return result;
    }
};