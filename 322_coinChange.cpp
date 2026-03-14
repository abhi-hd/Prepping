/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
start with -1 in matrix, but use INT_MAX in the recursion, it's simpler
remember temp + 1 , need a separate int for this or INT_MAX will overflow
in recursion, return INT_MAX instead of -1 in outside boundary conditions
*/
class Solution
{
public:
    vector<vector<int>> store;
    int coinChange(vector<int> &coins, int amount)
    {
        store.resize(amount + 1, vector<int>(coins.size(), -1));
        int result = recurse(coins, amount, 0);
        return result == INT_MAX ? -1 : result;
    }
    int recurse(vector<int> &coins, int amount, int index)
    {
        if (amount < 0 || index >= coins.size())
            return INT_MAX;
        if (amount == 0)
            return 0;
        if (store[amount][index] != -1)
            return store[amount][index];

        int result = INT_MAX;
        for (int i = index; i < coins.size(); i++)
        {
            int temp = recurse(coins, amount - coins[i], i);
            if (temp != INT_MAX)
                result = min(result, temp + 1);
        }
        return store[amount][index] = result;
    }
};