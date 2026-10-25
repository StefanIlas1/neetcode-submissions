// The map stores a value and an iterator for each key.
// The iterator acts as a tracker: it points to the key's node in the
// usage-order list, letting you remove that node quickly.

// The list tracks usage order.
// std::list is a doubly linked list.
// The ListNode structure used in earlier problems was singly linked.

// The constructor saves the supplied capacity in the object's member.

// In get(), remove the key's old list node to rearrange its position.
// Add the key again at the back to mark it as most recently used.

// end() means the position AFTER the last element, not the last element.
// Decrementing it with -- gives an iterator to the last element.
// Store that iterator in the map to track the key's new list node.

// Return cache[key].first to retrieve the stored value.

// cache.find(key) == cache.end() means the key wasn't found.
// cache.find(key) != cache.end() means the key was found.

// Eviction happens when inserting a new key into a full cache.
// order.front() accesses the first key: the least recently used one.
// order.pop_front() removes its list node.
// cache.erase(lru) removes its map entry.


//cache -> has a size capacity, returns value corresponding to the key 
// update key if key exists, // exceeds capacity? pop
//O(1)


class LRUCache {
unordered_map<int, pair<int, list<int>::iterator>> cache;
list<int> order;
int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) { return -1;}
        order.erase(cache[key].second);
        order.push_back(key);

        cache[key].second = --order.end();
        return cache[key].first;        
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
        }
        else if(cache.size() == capacity) {
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
