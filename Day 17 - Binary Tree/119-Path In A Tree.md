### [Path In A Tree](https://www.codingninjas.com/studio/problems/path-in-a-tree_8230860?challengeSlug=striver-sde-challenge)

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


vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> ans;
	if(root == NULL) return ans;
	solve(root, x, ans);
	return ans;
}

/*
TC: O(N)
SC: O(N)
*/
```