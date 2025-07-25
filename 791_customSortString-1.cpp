/*
791. Custom Sort String

You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

Input: order = "cba", s = "abcd"

Output: "cbad"
*/
class Solution
{
public:
    struct comparator
    {
        vector<int> positions;
        comparator(vector<int> pos) : positions(pos) {}
        bool operator()(char &a, char &b)
        {
            return positions[a - 'a'] < positions[b - 'a'];
        }
    };
    string customSortString(string order, string s)
    {
        vector<int> pos(26, 0);
        for (int i = 0; i < order.size(); i++)
            pos[order[i] - 'a'] = i;
        sort(s.begin(), s.end(), comparator(pos));
        return s;
    }
};