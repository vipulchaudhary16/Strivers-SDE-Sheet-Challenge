### [Stack Implementation Using Array](https://www.codingninjas.com/studio/problems/stack-implementation-using-array_8230854?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    
    vector<int> stack;
    int size;
    int capacity;
    Stack(int capacity) {
        this->capacity = capacity;
        stack.resize(capacity);
        size = 0;
    }

    void push(int num) {
        if(this->isFull()) return;
        for(int i = size-1; i >=0; i--) stack[i+1] = stack[i];
        stack[0] = num;
        size++;
    }

    int pop() {
        if(isEmpty()) return -1;
        int top = stack[0];
        for(int i=1; i < size; i++) stack[i-1] = stack[i];
        size--;
        return top;
    }
    
    int top() {
        if(isEmpty()) return -1;
        return stack[0];
    }
    
    int isEmpty() {
        return size <= 0;
    }
    
    int isFull() {
        return size == capacity;
    }
    
};
```