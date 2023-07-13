### [BST Iterator](https://www.codingninjas.com/studio/problems/bst-iterator_8230815?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
class BSTiterator
{
    public:
    vector<int> in;
    int it;
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        it = 0;
        inorder(root, in);

    }

    void inorder(TreeNode<int> *root, vector<int> &ans) {
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    int next()
    {
        // write your code here
        if(!hasNext()) return -1;
        return in[it++];
    }

    bool hasNext()
    {
        // write your code here
        return it < in.size();
    }
};
```

#### Optimized Approach: 
```cpp
class BSTiterator
{
    private: stack<TreeNode<int>*> st;
    public:
    BSTiterator(TreeNode<int> *root)
    {
       pushAllLeft(root);
    }

    int next()
    {
        auto top = st.top(); st.pop();
        pushAllLeft(top->right);
        return top->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void pushAllLeft(TreeNode<int> *root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
};
```