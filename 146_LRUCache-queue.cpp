/*
146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
*/
class LRUCache
{
private:
    int size;
    unordered_map<int, int> pairs, freq;
    queue<int> keys;

public:
    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if (pairs.find(key) == pairs.end())
            return -1;
        keys.push(key);
        freq[key]++;
        return pairs[key];
    }

    void put(int key, int value)
    {
        keys.push(key);
        freq[key]++;
        pairs[key] = value;
        while (freq.size() > size)
        {
            int next = keys.front();
            keys.pop();
            freq[next]--;
            if (freq[next] == 0)
            {
                freq.erase(next);
                pairs.erase(next);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */