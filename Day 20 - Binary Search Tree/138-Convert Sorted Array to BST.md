### [Convert Sorted Array to BST](https://www.codingninjas.com/studio/problems/convert-sorted-array-to-bst_8230836?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
TreeNode<int> *solve(vector<int> &arr, int l, int h){
  if(l > h) return NULL;

  int m = (l+h)/2;
  TreeNode<int> *root = new TreeNode<int>(arr[m]);

  root->left = solve(arr, l, m-1);
  root->right = solve(arr, m+1, h);

  return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return solve(arr, 0, n-1);
}
/*
TC = O(n)
SC = O(1)
*/
```