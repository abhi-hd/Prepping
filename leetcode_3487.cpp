class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        unordered_set<int> store;
        int currSum = 0, maxVal = INT_MIN;
        for (auto num : nums)
        {
            if (store.count(num) == 0 && num > 0)
            {
                currSum += num;
                store.insert(num);
            }
            maxVal = max(maxVal, num);
        }
        return store.size() == 0 ? maxVal : currSum;
    }
};