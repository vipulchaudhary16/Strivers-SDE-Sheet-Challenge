### [Invert a Binary Tree](https://www.codingninjas.com/studio/problems/invert-a-binary-tree_8230838?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

bool storParents(TreeNode<int> *root, stack<TreeNode<int> *> &parents, TreeNode<int> *leaf){
  parents.push(root);

  if (!root->left and !root->right) {
    if (root->data == leaf->data)
      return true;
    else
      parents.pop();
    return false;
  }

  if (root->left) {
    if (storParents(root->left, parents, leaf))
      return true;
  }

  if (root->right) {
    if (storParents(root->right, parents, leaf))
      return true;
  }

  parents.pop();
  return false;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf) {
  if (!root) return NULL;

  stack<TreeNode<int> *> parents;
  storParents(root, parents, leaf);

  TreeNode<int> *head = parents.top();
  parents.pop();

  TreeNode<int> *resultRoot = head;

  while (!parents.empty()) {
    auto p = parents.top();
    parents.pop();

    if (p->right == head) {
      p->right = p->left;
      p->left = NULL;
    } else {
      p->left = NULL;
    }

    head->left = p;
    head = p;
  }

  return resultRoot;
}

```

### [Invert a Binary Tree](https://leetcode.com/problems/invert-binary-tree/)

```cpp
class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode * right = root -> right;
        root -> right = root -> left;
        root -> left = right;
        
        invertTree(root -> left);
        invertTree(root -> right);
        
        return root;
    }
};
```