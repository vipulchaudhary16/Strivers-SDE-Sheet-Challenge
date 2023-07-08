### [Construct Binary Tree From Inorder and Preorder Traversal](https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-preorder-traversal_8230759?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

TreeNode<int> * solve(int s, int e, vector<int> &preorder, int &preInd, unordered_map<int, int> &inMap){
    if(s > e) return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[preInd]);
    int inInd = inMap[preorder[preInd]];
    preInd++;
    root->left = solve(s, inInd-1, preorder, preInd, inMap);
    root->right = solve(inInd+1, e, preorder, preInd, inMap);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    unordered_map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
    int preInd = 0;
    return solve(0, inorder.size()-1, preorder, preInd, inMap);

}
```