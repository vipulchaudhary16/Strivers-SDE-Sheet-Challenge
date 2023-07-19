### [Convert A Given Binary Tree To Doubly Linked List](https://www.codingninjas.com/studio/problems/convert-a-given-binary-tree-to-doubly-linked-list_8230744?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
void makeDLL(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&head, BinaryTreeNode<int> *&prev){
    if(!root) return;

    makeDLL(root->left, head, prev);

    if(!prev){
        head = root;
        prev = root;
    } else {
        auto tempRoot = root;
        prev->right = root;
        root->left = prev;
        prev = tempRoot;
    }

    makeDLL(root->right, head, prev);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head=NULL, *prev = NULL;
    makeDLL(root,head,prev);
    return head;
}
```