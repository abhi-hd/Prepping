/*
636. Exclusive Time of Functions
On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n-1.

Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is the current function being executed. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list logs, where logs[i] represents the ith log message formatted as a string "{function_id}:{"start" | "end"}:{timestamp}". For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function call with function ID 1 ended at the end of timestamp 2. Note that a function can be called multiple times, possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time for the function with ID i.
Input: n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
Output: [7,1]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls function 1.
Function 1 starts at the beginning of time 6, executes 1 unit of time, and ends at the end of time 6.
Function 0 resumes execution at the beginning of time 6 and executes for 2 units of time.
So function 0 spends 2 + 4 + 1 = 7 units of total time executing, and function 1 spends 1 unit of total time executing.
*/
class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<vector<string>> sepLogs = parse(logs);
        vector<int> result(n, 0);
        stack<pair<int, int>> store;
        int currTime = 0;
        for (auto &log : sepLogs)
        {
            currTime = stoi(log[2]);
            if (log[1] == "start")
            {
                if (!store.empty())
                {
                    result[store.top().first] += currTime - store.top().second;
                }
                store.push({stoi(log[0]), stoi(log[2])});
            }
            else
            {
                result[store.top().first] += currTime - store.top().second + 1;
                store.pop();
                if (!store.empty())
                    store.top().second = currTime + 1;
            }
        }
        return result;
    }
    vector<vector<string>> parse(vector<string> &logs)
    {
        vector<vector<string>> result;
        char delimiter = ':';
        for (auto log : logs)
        {
            vector<string> tokens;
            stringstream ss(log);
            string token;
            while (getline(ss, token, delimiter))
            {
                tokens.push_back(token);
            }
            result.push_back(tokens);
        }
        return result;
    }
};