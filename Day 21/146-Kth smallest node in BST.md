### [Kth smallest node in BST](https://www.codingninjas.com/studio/problems/kth-smallest-node-in-bst_8230751?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
void findKthSmall(TreeNode<int>*root, int &ans,int &k){
  if(!root || k <= 0) return;
  findKthSmall(root->left, ans, k); //reverse in-order
  k--;
  if(k == 0){
      ans = root->data;
      return;
  }
  findKthSmall(root->right, ans, k);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int ans = -1;
    findKthSmall(root, ans, k);
    return ans;
}
```