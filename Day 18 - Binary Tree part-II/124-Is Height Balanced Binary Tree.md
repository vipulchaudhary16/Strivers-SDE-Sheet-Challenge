### [Is Height Balanced Binary Tree](https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_8230771?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
pair<int, bool> solve(BinaryTreeNode<int>* root){
    if(!root) return {0, true};

    auto lst = solve(root->left);
    auto rst = solve(root->right);

    bool isBalanced = abs(lst.first - rst.first) <= 1;

    return {1 + max(lst.first, rst.first), 
    lst.second && rst.second && isBalanced};
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    return solve(root).second;
}
```