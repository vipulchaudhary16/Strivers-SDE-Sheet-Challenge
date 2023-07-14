### [Size of Largest BST in Binary Tree](https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_8230743?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force
```cpp
#include <bits/stdc++.h> 
bool validate(TreeNode<int> *root, int lowerBound, int higherBound){
    if(!root) return true;

    if(root->data >= higherBound || root->data <= lowerBound) return false;

    bool lst = validate(root->left, lowerBound, root->data);
    bool rst = validate(root->right, root->data, higherBound);

    return lst && rst;
}

void findNodeCount(TreeNode<int>* node, int &k){
    if(!node) return;
    findNodeCount(node->left, k);
    k++;
    findNodeCount(node->right, k);
}

void solve(TreeNode<int>* root, int &maxi){
    if(!root) return;

    if(validate(root, INT_MIN, INT_MAX)){
        int k = 0;
        findNodeCount(root, k);
        maxi = max(maxi, k);
    }

    solve(root->left, maxi);
    solve(root->right, maxi);
}

int largestBST(TreeNode<int>* root) 
{
    int maxi = 0;
    solve(root, maxi);
    return maxi;
}

/*
TC = O(N^2)
SC = O(1)
*/

```