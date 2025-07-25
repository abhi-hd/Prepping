class Solution
{
public:
    vector<int> sxor;
    vector<unordered_set<int>> desc;
    vector<vector<int>> graph;
    void dfs(int node, int parent, vector<int> &nums)
    {
        sxor[node] = nums[node];
        desc[node].insert(node);

        for (auto neighbor : graph[node])
        {
            if (neighbor != parent)
            {
                dfs(neighbor, node, nums);
                desc[node].insert(desc[neighbor].begin(), desc[neighbor].end());
                sxor[node] ^= sxor[neighbor];
            }
        }
    }
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        sxor.resize(n, 0);
        graph.resize(n, vector<int>());
        desc.assign(n, unordered_set<int>());
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, nums);
        int total_xor = sxor[0];
        int result = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int xor_i = sxor[i];
                int xor_j = sxor[j];
                int val1, val2, val3;
                if (desc[i].count(j))
                {
                    val1 = xor_j;
                    val2 = xor_i ^ xor_j;
                    val3 = total_xor ^ xor_i;
                }
                else if (desc[j].count(i))
                {
                    val1 = xor_i;
                    val2 = xor_j ^ xor_i;
                    val3 = total_xor ^ xor_j;
                }
                else
                {
                    val1 = xor_i;
                    val2 = xor_j;
                    val3 = total_xor ^ xor_i ^ xor_j;
                }
                result = min(result, max({val1, val2, val3}) - min({val1, val2, val3}));
            }
        }
        return result;
    }
};