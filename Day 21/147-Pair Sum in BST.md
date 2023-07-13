### [Pair Sum in BST](https://www.codingninjas.com/studio/problems/pair-sum-in-bst_8230756?challengeSlug=striver-sde-challenge)

#### Brute force

```cpp
#include <bits/stdc++.h> 
void findInOrder(BinaryTreeNode<int> *root, vector<int> &in){
    if(!root) return;

    findInOrder(root->left, in);
    in.push_back(root->data);
    findInOrder(root->right, in);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> in;
    findInOrder(root, in);

    int i=0, j = in.size()-1;

    while(i < j){
        int sum = in[i] + in[j];
        if(sum == k) return true;
        else if(sum > k){
            j--;
        } else {
            i++;
        }
    }

    return false;
}
/*
TC = O(n)
SC = O(n)
*/
```

#### optimized

```cpp
#include <bits/stdc++.h> 
class Iterator{
    private: stack<BinaryTreeNode<int> *> st;
    
    public:
    bool isBefore = true;

    Iterator(BinaryTreeNode<int>*root, bool isBefore){
        this->isBefore = isBefore;
        pushAll(root);
    }

    void pushAll(BinaryTreeNode<int> *root){
        while(root){
            st.push(root);
            if(isBefore){
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }

    int next(){
        auto temp = st.top(); st.pop();
        if(isBefore) pushAll(temp->left);
        else pushAll(temp->right);
        return temp->data;
    }

};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(!root) return false;
    Iterator l(root, false);
    Iterator r(root, true);
    
    int i = l.next(); 
    int j = r.next();

    while(i < j){
        if(i+j == k) return true;
        else if(i+j < k) i = l.next();
        else j = r.next();
    }

    return false;
}
```