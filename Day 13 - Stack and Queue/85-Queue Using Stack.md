### [Queue Using Stack](https://www.codingninjas.com/studio/problems/day-25-queue-using-stack_8230722?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <stack>
using namespace std;

class Queue {
    public:
    stack<int> st;
    Queue() {
    }

    void enQueue(int val) {
        stack<int> temp; // temporary stack to store the elements of the main stack
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(val); // push the new element to the main stack
        while(!temp.empty()){ // push the elements back to the main stack
            st.push(temp.top());
            temp.pop();
        }
    }
    /*
    TC: O(n)
    SC: O(n)
    */

    int deQueue() {
        if(isEmpty()) return -1;
        int top = st.top();
        st.pop();
        return top;
    }

    int peek() {
        if(isEmpty()) return -1;
        return st.top();
    }

    bool isEmpty() {
        return st.empty();
    }
};
```

#### Amortized Analysis

```cpp
#include <stack>
using namespace std;

class Queue {
    public:
    stack<int> in, out;
    Queue() {
    }

    void enQueue(int val) {
        in.push(val);
    }
    /*
    TC: O(1)
    SC: O(n)
    */

    int deQueue() {
        if(isEmpty()) return -1;
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        int top = out.top();
        out.pop();
        return top;
    }
    /*
    TC: O(1) amortized
    SC: O(n)
    */

    int peek() {
        if(isEmpty()) return -1;
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    /*
    TC: O(1) amortized
    SC: O(n)
    */

    bool isEmpty() {
        return in.empty() &&  out.empty();
    }
};
```