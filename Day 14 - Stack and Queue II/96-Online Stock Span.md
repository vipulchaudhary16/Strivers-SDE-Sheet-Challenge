### [Online Stock Span](https://www.codingninjas.com/studio/problems/online-stock-span_8230843?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector<int> ans(n, 1);
    stack<int> st;
    st.push(0);

    for(int i = 1; i < n; i++){
        while(!st.empty() and price[st.top()] <= price[i]){
            st.pop();
        }
        ans[i] = st.empty() ? i+1 : i - st.top();
        st.push(i);
    }

    return ans;
}
```