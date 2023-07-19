### [Kth Largest Element In A Stream](https://www.codingninjas.com/studio/problems/kth-largest-element-in-a-stream_8230728?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K; // Kth largest element in the stream
    Kthlargest(int k, vector<int> &arr) {
        K = k; // initialize K
        for(auto &num : arr) {
            pq.push(num);
            if(pq.size() > K) // we only need to store K elements in the priority queue
                pq.pop();
        }
    }

    void add(int num) {
        pq.push(num);
        if(pq.size() > K) // we only need to store K elements in the priority queue
            pq.pop();
    }

    int getKthLargest() {
        return pq.top();
    }

};
```