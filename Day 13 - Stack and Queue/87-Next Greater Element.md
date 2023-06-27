### [Next Greater Element](https://www.codingninjas.com/studio/problems/next-greater-element_8230718?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> nge(n, -1);

    for(int i = n-1; i >= 0; i--){
      // Pop all elements from stack which are smaller than current element
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
      // If stack is not empty, then the top element is the next greater element
        if(!st.empty()) nge[i] = st.top();
        st.push(arr[i]);
    }

    return nge;
}
/*
TC: O(n)
SC: O(n)
*/
```