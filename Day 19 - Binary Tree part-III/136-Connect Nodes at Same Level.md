### [Connect Nodes at Same Level](https://www.codingninjas.com/studio/problems/connect-nodes-at-same-level_8230790?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
  if(!root) return;
  queue<BinaryTreeNode<int> *> q;
  q.push(root);

  while(!q.empty()){
    int sz = q.size();
    vector<BinaryTreeNode<int>*> v;

    for(int i = 0; i < sz; i++){
      auto top = q.front(); q.pop();
      if(i != sz-1) top->next = q.front(); //ignore last node
      if(top->left) q.push(top->left);
      if(top->right) q.push(top->right);
    }

  }
}
```
