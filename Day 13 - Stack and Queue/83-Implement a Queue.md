### [Implement a Queue](https://www.codingninjas.com/studio/problems/implement-a-queue_8230848?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> queue;
    Queue() {
    }


    bool isEmpty() {
        return queue.size() == 0;
    }

    void enqueue(int data) {
        queue.push_back(data);
    }

    int dequeue() {
        if(this->isEmpty()) return -1;

        int front = queue[0];
        for(int i = 1; i < queue.size(); i++) queue[i-1] = queue[i];
        queue.pop_back();
        return front;
    }

    int front() {
        if(this->isEmpty()) return -1;
        return queue[0];
    }
};
```