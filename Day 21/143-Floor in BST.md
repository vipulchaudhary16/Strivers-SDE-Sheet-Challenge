### [Floor in BST](https://www.codingninjas.com/studio/problems/floor-in-bst_8230753?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    TreeNode<int> *tempRoot = root;

    while(tempRoot){
        if(tempRoot->val == X){
            return tempRoot->val;
        }
        if(tempRoot->val > X){
            tempRoot = tempRoot->left;
        } else {
            ans = tempRoot->val;
            tempRoot = tempRoot->right;
        }
    }

    return ans;
}
```