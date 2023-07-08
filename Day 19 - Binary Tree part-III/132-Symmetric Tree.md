### [Symmetric Tree](https://www.codingninjas.com/studio/problems/symmetric-tree_8230686?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
bool solve(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right){
    if(!left || !right) return left == right;

    if(left->data != right->data) return false;

    bool lst = solve(left->left, right->right);
    bool rst = solve(left->right, right->left);

    return lst && rst;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root) return true;
    return solve(root->left, root->right);
}
```