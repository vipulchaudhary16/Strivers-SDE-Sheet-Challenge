### [Boundary Traversal of Binary Tree](https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_8230712?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
void leftSide(TreeNode<int> *root, vector<int> &res) {
    if (!root || (!root->left && !root->right))
        return;

    res.push_back(root->data);

    if (root->left)
        leftSide(root->left, res);
    else
        leftSide(root->right, res);
}

void rightSide(TreeNode<int> *root, vector<int> &res) {
    if (!root || (!root->left && !root->right))
        return;

    if (root->right)
        rightSide(root->right, res);
    else
        rightSide(root->left, res);

    res.push_back(root->data);
}

void leaves(TreeNode<int> *root, vector<int> &res) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        res.push_back(root->data);
        return;
    }

    leaves(root->left, res);
    leaves(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int> *root) {
    if (!root)
        return {};

    vector<int> res;
    res.push_back(root->data);

    leftSide(root->left, res);
    leaves(root->left, res);
    leaves(root->right, res);
    rightSide(root->right, res);

    return res;
}
```