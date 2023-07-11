### [Partial BST](https://www.codingninjas.com/studio/problems/partial-bst_8230723?challengeSlug=striver-sde-challenge)

```cpp
bool validate(BinaryTreeNode<int> *root, int lowerBound, int higherBound){
    if(!root) return true;

    if(root->data > higherBound || root->data < lowerBound) return false;

    bool lst = validate(root->left, lowerBound, root->data);
    bool rst = validate(root->right, root->data, higherBound);

    return lst && rst;
}


bool validateBST(BinaryTreeNode<int> *root) {
    if(!root) return true;
    return validate(root, INT_MIN, INT_MAX);
}
```