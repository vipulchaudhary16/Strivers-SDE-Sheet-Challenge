### [LRU Cache Implementation](https://www.codingninjas.com/studio/problems/lru-cache-implementation_8230697?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>

class LRUCache {
  public:
    class node {
      public:
        int key;
        int val;
        node * next;
        node * prev;
        node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);

    int capacity;
    unordered_map<int, node * > m;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addAfterHead(node * newnode) {
        // store next of head node
        node * temp = head -> next;
        // create connection between new node and head next node
        newnode -> next = temp; 
        newnode -> prev = head; 
        // create connection between new node and head
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletenode(node * delnode) {
        // save connection of deleting node
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        // remove connections
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key) {
        // if key is present in map
        if (m.find(key) != m.end()) {
            node * resnode = m[key];
            int res = resnode -> val;
            // remove from DLL
            deletenode(resnode);
            // add next to head, as it is LRU
            addAfterHead(resnode);
            // update into map
            m[key] = head -> next;
            return res;
        }

        return -1;
    }

    void put(int key, int value) {
        // if already present in cache
        if (m.find(key) != m.end()) {
            node * existingnode = m[key];
            // erase from map
            m.erase(key);
            // remove from DLL
            deletenode(existingnode);
        }
        // if capacity is full
        if (m.size() == capacity) {
            // remove LRU
            m.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }

        // add into DLL
        addAfterHead(new node(key, value));
        m[key] = head -> next;
    }
};
```

### Using STL

```cpp
#include <list>
#include <unordered_map>

class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            auto itr = m[key];
            auto res = *itr;
            cache.erase(itr);
            cache.push_front(res);
            m[key] = cache.begin();
            return res.second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            cache.erase(m[key]);
        }
        if (cache.size() == capacity) {
            int lastKey = cache.back().first;
            m.erase(lastKey);
            cache.pop_back();
        }
        cache.push_front(std::make_pair(key, value));
        m[key] = cache.begin();
    }
};

``` 