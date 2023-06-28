### [LFU Cache](https://www.codingninjas.com/studio/problems/lfu-cache_8230851?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
class LFUCache
{
public:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> cache; //{key -> {val, freq}}
    unordered_map<int, list<int>> freq_map; // {freq -> [key]}
    unordered_map<int, list<int>::iterator> position; //{key -> addressInList}

    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
    }

    void transferFreq(int key, int oldFreq){
        freq_map[oldFreq].erase(position[key]); //remove from old freq
        oldFreq++; //increase freq
        freq_map[oldFreq].push_front(key); //add to new freq list
        position[key] = freq_map[oldFreq].begin(); //update position
    }

    int get(int key)
    {
       if(cache.count(key) != 0){
           int oldFreq = cache[key].second; //old freq
           transferFreq(key, oldFreq);
           if(freq_map[minFreq].empty()) minFreq++; //update min freq if all removed 
           return cache[key].first; //return value from cache
       }
       return -1;
    }

    void put(int key, int value)
    {
        if(cache.count(key) != 0){
            //present
            cache[key].first = value; //update value
            int oldFreq = cache[key].second; //old freq of key
            transferFreq(key, oldFreq);
            if(freq_map[minFreq].empty()) minFreq++;
        } else {
            if(capacity == cache.size()){
                //cache full, remove LFU
                int minKey = freq_map[minFreq].back();
                cache.erase(minKey);
                position.erase(minKey);
                freq_map[minFreq].pop_front();
            }
            cache[key] = {value, 1};
            freq_map[1].push_front(key);
            position[key] = freq_map[1].begin();
            minFreq = 1;
        }
    }
};

```