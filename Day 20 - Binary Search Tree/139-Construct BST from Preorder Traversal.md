### [Construct BST from Preorder Traversal](https://www.codingninjas.com/studio/problems/construct-bst-from-preorder-traversal_8230850?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force

```cpp
TreeNode<int> * solve(int s, int e, vector<int> &preorder, int &preInd, unordered_map<int, int> &inMap){
    if(s > e) return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[preInd]);
    int inInd = inMap[preorder[preInd]];
    preInd++;
    root->left = solve(s, inInd-1, preorder, preInd, inMap);
    root->right = solve(inInd+1, e, preorder, preInd, inMap);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    vector<int> preTemp = preOrder;
    sort(preTemp.begin(), preTemp.end());
    vector<int> inOrder = preTemp;
    unordered_map<int, int> inMap;
    for(int i = 0; i < inOrder.size(); i++) inMap[inOrder[i]] = i;
    int preInd = 0;
    return solve(0, inOrder.size()-1, preOrder, preInd, inMap);
}
/*
TC = O(nlogn)
SC = O(n)
*/
```

#### Optimized 
```cpp
TreeNode<int> *solve(vector<int> pre, int &ind, int bound){
    if(ind == pre.size() || pre[ind] > bound) return NULL;
    
    TreeNode<int> *root = new TreeNode<int>(pre[ind]);
    ind++;
    root->left = solve(pre, ind, root->data);
    root->right = solve(pre, ind, bound);

    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i = 0;
    return solve(preOrder, i, INT_MAX);
}
/*
TC = O(n)
SC = O(n)
*/
```