### [Check Identical Trees](https://www.codingninjas.com/studio/problems/check-identical-trees_8230719?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(!root1 and !root2) return true;
    
    if((!root1 && root2) || (root1 && !root2)){
        return false;
    }

    if(root1->data != root2->data ) return false;

    bool left = identicalTrees(root1->left, root2->left);
    bool right = identicalTrees(root1->right, root2->right);

    return left && right;
}
```