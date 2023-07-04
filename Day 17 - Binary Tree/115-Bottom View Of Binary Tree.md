### [Bottom View Of Binary Tree](https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_8230745?challengeSlug=striver-sde-challenge)

#### Using level order traversal
```cpp
vector<int> bottomView(BinaryTreeNode<int> *root) {
    map<int, map<int, list<int>>> nodes; // {hDist -> {level, [values]}}
    queue<pair<BinaryTreeNode<int>*, pair<int, int>>> q; // {node, {hD, level}}

    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto qFront = q.front();
        q.pop();

        auto node = qFront.first;
        int hd = qFront.second.first;
        int lvl = qFront.second.second;

        nodes[hd][lvl].push_back(node->data);

        if (node->left) {
            q.push({node->left, {hd - 1, lvl + 1}});
        }

        if (node->right) {
            q.push({node->right, {hd + 1, lvl + 1}});
        }
    }

    vector<int> result;

    for (auto it : nodes) {
        // last level of every horizontal distance
        auto lastLevel = (--it.second.end())->second;
        // --it because we want to access the last element of the map
        // last element of last level of every horizontal distance is bottom view
        result.push_back(lastLevel.back());
    }

    return result;
}
/*
TC: O(N)
SC: O(N)
*/
```