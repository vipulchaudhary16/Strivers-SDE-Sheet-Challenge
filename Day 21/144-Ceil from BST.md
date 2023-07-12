### [Ceil from BST](https://www.codingninjas.com/studio/problems/ceil-from-bst_920464?topList=striver-sde-sheet-problems&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans  = -1;
    while(node){
        if(node->data == x) return x;
        if(node->data > x){
            ans = node->data;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return ans;
}
```