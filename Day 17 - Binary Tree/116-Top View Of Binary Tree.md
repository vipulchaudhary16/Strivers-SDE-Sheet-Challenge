### [Top View Of Binary Tree](https://www.codingninjas.com/studio/problems/top-view-of-binary-tree_8230721?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
vector<int> getTopView(TreeNode<int> *root) {
    if(!root) return {};

    map<int, int> nodes; // {lvl, value}
    queue<pair<TreeNode<int>*, int>> q; // {node, {hD, level}}

    q.push({root, 0});

    while (!q.empty()) {
        auto qFront = q.front();
        q.pop();

        auto node = qFront.first;
        int hd = qFront.second;

        if(nodes.find(hd) == nodes.end())
            nodes[hd] = node->val;

        if(node->left) {
            q.push({node->left, hd-1});
        }

        if(node->right) {
            q.push({node->right, hd+1});
        }
    }

    vector<int> result;

    for (auto it : nodes) {
        result.push_back(it.second);
    }

    return result;
}
```