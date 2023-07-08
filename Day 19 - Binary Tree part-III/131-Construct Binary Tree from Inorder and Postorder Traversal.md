### [Construct Binary Tree from Inorder and Postorder Traversal](https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_8230837?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>
TreeNode<int> * solve(vector<int> &in, int is, int ie, 
vector<int> &post, int ps, int pe, unordered_map<int, int> &mp){
     if(is > ie || ps > pe) return NULL;

     TreeNode<int> *root = new TreeNode<int>(post[pe]);
     int rootInd = mp[post[pe]];
     int numInLeft = rootInd - is;

     root->left = solve(in, is, rootInd-1, post, ps, ps+numInLeft-1, mp);
     root->right = solve(in, rootInd+1, ie, post, ps+numInLeft, pe-1, mp);

     return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     unordered_map<int, int> inMap;
     int n = inOrder.size();
     for(int i = 0; i < n; i++) inMap[inOrder[i]] = i;
     return solve(inOrder, 0, n-1, postOrder, 0, n-1, inMap);
}

```