### [LCA of Two Nodes In A BST](https://www.codingninjas.com/studio/problems/lca-of-two-nodes-in-a-bst_8230778?challengeSlug=striver-sde-challenge)

#### Brute Force
```cpp
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(!root || root == P || root == Q) return root;

    auto left = LCAinaBST(root->left, P, Q);
    auto right = LCAinaBST(root->right, P, Q);

    if(!left) return right;
    else if(!right) return left;
    else return root;
}
/*
TC: O(N)
SC: O(N) // recursion stack
*/
```

#### Optimized
```cpp
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(!root) return root;

    int rootVal = root->data;

    if(rootVal < P->data && rootVal < Q->data){
        return LCAinaBST(root->right, P, Q);
    }

    if(rootVal > P->data && rootVal > Q->data){
        return LCAinaBST(root->left, P, Q);
    }

    return root;
}
/*
TC: O(H) // H is the height of the tree
SC: O(N) // recursion stack
*/
```