### [Flatten Binary Tree to Linked List](https://www.codingninjas.com/studio/problems/flatten-binary-tree-to-linked-list_8230817?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
void solve(TreeNode<int> *root, TreeNode<int>* &prev){
    if(!root) return;

    solve(root->right, prev);
    solve(root->left, prev);

    root->right = prev;
    root->left = NULL;

    prev = root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *prev = NULL;
    solve(root, prev);
    return prev;
}
```