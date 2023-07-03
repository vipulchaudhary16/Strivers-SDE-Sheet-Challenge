### [Postorder Traversal](https://www.codingninjas.com/studio/problems/postorder-traversal_8230858?challengeSlug=striver-sde-challenge)

```cpp
void solve(TreeNode *root,vector<int>& ans){
    if(root == NULL){
        return;
    }
    solve(root->left,ans);
    solve(root->right,ans);
    ans.push_back(root->data);
    return;
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    solve(root,ans);
    return ans;
}
```