### [Search In BST](https://www.codingninjas.com/studio/problems/search-in-bst_8230841?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
bool searchInBST(BinaryTreeNode<int> *root, int x) {
  if(!root) return false;
  if(root->data < x) searchInBST(root->right, x);
  else if(root->data > x) searchInBST(root->left, x);
  else return true;
}
```