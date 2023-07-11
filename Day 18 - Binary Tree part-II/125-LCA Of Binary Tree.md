### [LCA Of Binary Tree](https://www.codingninjas.com/studio/problems/lca-of-binary-tree_8230760?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

void solve(TreeNode<int> *node, int x, vector<int> &ans){
	if(node == NULL) return;
	ans.push_back(node->data);
	if(node->data == x) return;

	solve(node->left, x, ans);
	solve(node->right, x, ans);
	if(ans.back() != x)
		ans.pop_back();
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	vector<int> path1;
  solve(root, x, path1);
  vector<int> path2;
  solve(root, y, path2);

  for(int i = 0; i < min(path1.size(), path2.size()); i++){
    if(path1[i] != path2[i]) return path1[i-1];
    if(i == path1.size()-1) return path1[i];
    if(i == path2.size()-1) return path2[i];
  }

  return root->data;
}
/*
TC: O(N)
SC: O(N)
*/
```

#### Optimized Solution

```cpp
TreeNode<int> * lca(TreeNode<int> *root, int x, int y)
{
	if(!root || root->data == x || root->data == y) return root;

    auto left = lca(root->left, x, y);
    auto right = lca(root->right, x, y);

    if(!left) return right;
    else if(!right) return left;
    else return root;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return lca(root, x, y)->data;
}
```