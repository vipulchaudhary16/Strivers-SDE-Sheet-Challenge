### [Preorder Traversal](https://www.codingninjas.com/studio/problems/preorder-traversal_8230856?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
void getPreOrderTraversal(TreeNode *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    ans.push_back(root->data);
    getPreOrderTraversal(root->left, ans);
    getPreOrderTraversal(root->right, ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    getPreOrderTraversal(root, ans);
    return ans;
}
```