### [Children Sum Property](https://www.codingninjas.com/studio/problems/children-sum-property_8230711?challengeSlug=striver-sde-challenge)

```cpp
void changeTree(BinaryTreeNode < int > * root) {
    if(!root) return;

    int childSum = 0; // sum of children
    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;

    if(childSum >= root->data){ // if sum of children is greater than root
        root->data = childSum; // then make root equal to sum of children
    } else {
        // else make any one equal to root
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }

    changeTree(root->left); // call for left subtree
    changeTree(root->right); // call for right subtree

    int total = 0; // sum of children
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->right or root->left) root->data = total; // if any child is present then make root equal to sum of children
}  
```