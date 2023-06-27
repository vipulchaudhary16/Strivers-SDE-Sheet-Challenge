### [Next Smaller Element](https://www.codingninjas.com/studio/problems/next-smaller-element_8230814?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> nse(n, -1);
    for(int i = n-1; i >= 0; i--){
      // Pop all elements from stack which are greater than current element
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
      // If stack is not empty, then the top element is the next smaller element
        if(!st.empty()) nse[i] = st.top();
        st.push(arr[i]);
    }
    return nse;
}
/*
TC: O(n)
SC: O(n)
*/
```