/*
973. K Closest Points to Origin
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
*/
class Solution
{
public:
    struct comparator
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, comparator> store;
        for (auto point : points)
        {
            store.push(point);
            if (store.size() > k)
                store.pop();
        }
        vector<vector<int>> result;
        while (!store.empty())
        {
            result.push_back(store.top());
            store.pop();
        }
        return result;
    }
};