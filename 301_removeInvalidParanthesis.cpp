/*
301. Remove Invalid Parentheses
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

Input: s = "()())()"
Output: ["(())()","()()()"]
*/
class Solution
{
private:
    queue<string> buffer;
    unordered_set<string> visited;

public:
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> result;
        buffer.push(s);
        while (!buffer.empty())
        {
            int n = buffer.size();
            for (int i = 0; i < n; i++)
            {
                string current = buffer.front();
                buffer.pop();

                if (valid(current))
                {
                    result.push_back(current);
                }

                if (result.empty())
                {
                    for (int j = 0; j < current.size(); j++)
                    {
                        if (current[j] == '(' || current[j] == ')')
                        {
                            string next = current.substr(0, j) + current.substr(j + 1);
                            if (!visited.count(next))
                            {
                                visited.insert(next);
                                buffer.push(next);
                            }
                        }
                    }
                }
            }
            if (!result.empty())
            {
                return result;
            }
        }
        return {};
    }
    bool valid(string s)
    {
        int score = 0;
        for (auto c : s)
        {
            if (c == '(')
                score++;
            else if (c == ')')
                score--;
            if (score < 0)
                return false;
        }
        return score == 0;
    }
};