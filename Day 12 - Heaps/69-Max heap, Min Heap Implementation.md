### [Min Heap](https://www.codingninjas.com/codestudio/problems/min-heap_8230863?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### STL

```cpp
#include <bits/stdc++.h> 

vector<int> minHeap(int n, vector<vector<int>>& q) {
    priority_queue <int, vector<int>, greater<int>>  min_heap;
    vector<int> ans;
    
    for(int i=0; i < n; i++){
        if(q[i][0] == 0) min_heap.push(q[i][1]);
        else if(q[i][0] == 1) {
            ans.push_back(min_heap.top());
            min_heap.pop();
        }
    }

    return ans;
}

```