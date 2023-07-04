### [Tree Traversals](https://www.codingninjas.com/studio/problems/tree-traversals_8230775?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    if(!root) return {{}};
    stack<pair<BinaryTreeNode<int> *, int>> st;
    
    st.push({root, 1});

    vector<vector<int>> res(3, vector<int>());

    while(!st.empty()){
        auto top = st.top();
        st.pop();

        if(top.second == 1){
            //pre-order
            res[1].push_back(top.first->data);
            top.second++;
            st.push(top);

            if(top.first->left){
                st.push({top.first->left, 1});
            }
        } else if(top.second == 2){
            res[0].push_back(top.first->data);
            top.second++;
            st.push(top);

            if(top.first->right){
                st.push({top.first->right, 1});
            }
        } else {
            res[2].push_back(top.first->data);
        }
    }

    return res;

}
/**
TC: O(N)
SC: O(N)
*/
```