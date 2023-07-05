### [Maximum Width In Binary Tree](https://www.codingninjas.com/studio/problems/maximum-width-in-binary-tree_8230710?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

int getMaxWidth(TreeNode<int> *root)
{
    if(!root) return 0;

    queue<TreeNode<int> *> q;
    q.push(root);

    int ans = 0;
    while(!q.empty()){
        int sz = q.size();
        ans = max(ans, sz);

        while(sz--){
            auto top = q.front();
            q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
    }

    return ans;
}
/*
TC: O(N)
SC: O(N)
*/
```