### [Vertical Order Traversal](https://www.codingninjas.com/studio/challenges/striver-sde-challenge?activeProblems=true)

```cpp
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int, map<int, list<int>>> nodes; // {hDist -> {level, [values]}}
    queue<pair< TreeNode<int>*, pair<int, int> >> q; // {node, {hD, level}}

    q.push({root, {0, 0}});

    while(!q.empty()){
        auto qFront = q.front(); q.pop();

        auto node = qFront.first;
        int hd = qFront.second.first;
        int lvl = qFront.second.second;

        nodes[hd][lvl].push_back(node->data);

        if(node->left){
            // left child will have hd-1
            q.push({node->left, {hd-1, lvl+1}});
        }

        if(node->right){
            // right child will have hd+1
            q.push({node->right, {hd+1, lvl+1}});
        }
    }

    vector<int> result;

    for(auto it: nodes){
        for(auto it2: it.second){
            for(auto data: it2.second) result.push_back(data);
        }
    }

    return result;
}
/*
TC: O(N* logN)
SC: O(N)
*/
```

#### But we don't need level 

```cpp
vector<int> bottomView(BinaryTreeNode<int> *root) {
    map<int, int> nodes; // {lvl, value}
    queue<pair <BinaryTreeNode<int>*, int> > q; // {node, {hD, level}}

    q.push({root, 0});

    while (!q.empty()) {
        auto qFront = q.front();
        q.pop();

        auto node = qFront.first;
        int hd = qFront.second;

        nodes[hd] = node->data;

        if (node->left) {
            q.push({node->left, hd-1});
        }

        if (node->right) {
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