### [K-th largest Number BST](https://www.codingninjas.com/studio/problems/k-th-largest-number-bst_8230750?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
void findKthLarge(TreeNode<int>*root, int &ans,int &k){
  if(!root || k <= 0) return;
  findKthLarge(root->right, ans, k); //reverse in-order
  k--;
  if(k == 0){
      ans = root->data;
      return;
  }
  findKthLarge(root->left, ans, k);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
  int ans = -1;
  findKthLarge(root, ans, k);
  return ans;
}
/*
TC = O(K)
SC = O(1)
*/
```