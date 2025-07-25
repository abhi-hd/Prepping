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
    unordered_map<int, int> keyValueStore;
    unordered_map<int, list<int>::iterator> keyPositionStore;
    list<int> position;

public:
    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if (keyValueStore.find(key) == keyValueStore.end())
            return -1;
        position.erase(keyPositionStore[key]);
        position.push_front(key);
        keyPositionStore[key] = position.begin();
        return keyValueStore[key];
    }

    void put(int key, int value)
    {
        keyValueStore[key] = value;
        if (keyPositionStore.find(key) != keyPositionStore.end())
        {
            position.erase(keyPositionStore[key]);
        }
        position.push_front(key);
        keyPositionStore[key] = position.begin();

        if (position.size() > size)
        {
            int toRemove = position.back();
            position.pop_back();
            keyValueStore.erase(toRemove);
            keyPositionStore.erase(toRemove);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */