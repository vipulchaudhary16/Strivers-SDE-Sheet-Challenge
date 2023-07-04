### [Left View Of a Binary Tree](https://www.codingninjas.com/studio/problems/left-view-of-a-binary-tree_8230757?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
vector<int> getLeftView(TreeNode<int> *root)
{
    if(!root) return {};
    queue<TreeNode<int> *> q;
    q.push(root);
    vector<int> ans;

    while(!q.empty()){
        int s = q.size();

        for(int i = 0; i < s; i++){
            auto top = q.front(); 
            q.pop();
            if(i == 0) ans.push_back(top->data); // first node of every level is left view

            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
    }

    return ans;
}
```