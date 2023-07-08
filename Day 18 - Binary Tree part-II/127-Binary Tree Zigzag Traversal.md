### [Binary Tree Zigzag Traversal](https://www.codingninjas.com/studio/problems/binary-tree-zigzag-traversal_8230796?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(!root) return {};
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    vector<int> res;
    bool l_to_r = true;

    while(!q.empty()){
        int sz = q.size();
        vector<int> temp(sz);

        for(int i = 0; i < sz; i++){
            auto top = q.front();
            q.pop();

            int ind = l_to_r ? i : sz-1-i;
            temp[ind] = top->data;

            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }

        l_to_r = !l_to_r;
        for(int data:temp) res.push_back(data);
    }

    return res;
}

```
