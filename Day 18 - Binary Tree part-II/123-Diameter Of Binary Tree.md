### [Diameter Of Binary Tree](https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_8230762?challengeSlug=striver-sde-challenge)

#### Brute force
```cpp
int height(TreeNode<int> *root){
  if(!root) return 0;
  return 1 + max(height(root->right), height(root->left));
}

void solve(TreeNode<int> * root, int &ans){
  if(!root) return;

  int lh = height(root->left);
  int rh = height(root->right);

  ans = max(ans, lh+rh);

  solve(root->left, ans);
  solve(root->right, ans);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int ans = 0;
  solve(root, ans);
  return ans;
}
/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
```

#### Optimized
```cpp
/*
The idea is to calculate the height of the tree in the same recursion call in which we are calculating the diameter of the tree. 
*/
int height(TreeNode<int> *root, int &ans){
  if(!root) return 0;

  int lh = height(root->left, ans);
  int rh = height(root->right, ans);

  ans = max(ans, (lh+rh));

  return 1+ max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int ans = 0;
  height(root, ans);
  return ans;
}
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
```
