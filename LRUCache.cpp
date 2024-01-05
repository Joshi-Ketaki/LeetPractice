/*
146. LRU Cache
Solved
Medium
Topics
Companies

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

 

Constraints:

    1 <= capacity <= 3000
    0 <= key <= 104
    0 <= value <= 105
    At most 2 * 105 calls will be made to get and put.


*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LRUCache {
    unordered_map<int, vector<int>> kvstore;
    queue<int> q;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
      if(kvstore.find(key) != kvstore.end())
      {
          q.push(key);
          kvstore[key][1]++;
          return kvstore[key][0];
      }
      else
        return -1;
    }
    
    void put(int key, int value) {
        if(kvstore.find(key) == kvstore.end())
        {
            kvstore[key] = {value,1};
            q.push(key);
        }
        else
        {
            kvstore[key][0] = value;
            kvstore[key][1]++;
            q.push(key);
        }

        if(kvstore.size() > cap)
        {
            while(!q.empty())
            {
                int knode = q.front();
                q.pop();
                kvstore[knode][1]--;
                if(kvstore[knode][1] == 0)
                {
                    kvstore.erase(knode);
                    break;
                }
            }
        }
    }
};
