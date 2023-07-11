### [Predecessor And Successor In BST](https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_8230742?challengeSlug=striver-sde-challenge)

```cpp
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int> *temp = root;

    int succ = -1;
    while(temp){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    temp = root;
    int pre = -1;
    while(temp){
        if(temp->data < key){
            pre = temp->data;
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }

    return {pre, succ};
}
```