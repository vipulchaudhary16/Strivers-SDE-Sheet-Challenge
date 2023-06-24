### [Stack using queue](https://www.codingninjas.com/studio/problems/stack-using-queue_8230715?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
class Stack {
   public:
    queue<int> q;

    Stack() {}

    int getSize() {
      return q.size();
    }

    bool isEmpty() {
      return q.empty();
    }

    void push(int element) {
      int s = q.size();
      q.push(element); // Push element to queue
      // Pop (or Dequeue) all previous elements and put them after current element
      while(s--){
        q.push(q.front());
        q.pop();
      }
    }

    int pop() {
      if(this->isEmpty()) return -1;
      int top = q.front();
      q.pop();
      return top;
    }

    int top() {
        if(this->isEmpty()) return -1;
        return q.front();
    }
};
```