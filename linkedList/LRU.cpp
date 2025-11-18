/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

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
At most 2 * 105 calls will be made to get and put.*/

// Intuiition: DLL to maintain the order. new/recently used added from tail. so the lru will  be towards the head

// TC: get/put: O(1) : lookup through map SC: O(capacity)

class LRUCache {
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    void removeNode(Node* removeNode)
    {
        removeNode->prev->next = removeNode->next;
        removeNode->next->prev = removeNode->prev;
    }
    void insertNodeAtTail(Node* insertNode)
    {
        // insert before tail
        insertNode->prev = tail->prev;
        tail->prev = insertNode;
        insertNode->prev->next = insertNode;
        insertNode->next = tail;
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        removeNode(cache[key]);
        insertNodeAtTail(cache[key]);
        return cache[key]->value;  
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            removeNode(node);
            // update value
            node->value = value;
            insertNodeAtTail(node);
        }
        else
        {
            Node* node = new Node(key,value);
            if(cache.size() == cap)
            {
                Node* remove = head->next; 
                removeNode(remove);
                cache.erase(remove->key);
                delete remove;
            }
            insertNodeAtTail(node);
            cache[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
