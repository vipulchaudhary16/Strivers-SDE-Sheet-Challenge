### [Level Order Traversal](https://www.codingninjas.com/studio/problems/level-order-traversal_8230716?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(!root) return {};

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    vector<int> res;
    while(!q.empty()){
        int sz = q.size();

        while(sz--){
            auto top = q.front();
            res.push_back(top->val);
            q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
    }

    return res;
}
```