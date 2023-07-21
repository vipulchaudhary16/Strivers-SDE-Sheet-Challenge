### [Strongly Connected Components](https://www.codingninjas.com/studio/problems/strongly-connected-components-tarjan-s-algorithm_8230789?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Kosaraju's Algorithm

```cpp
/*
We will start dfs from the node with the highest finishing time.
We will get a component.
That component will be a strongly connected component.
*/
#include<bits/stdc++.h>

void topoSort(int node, unordered_map<int, vector<int>> &adjList, vector<int> &visited,
vector<int> &res){
    visited[node] = 1;

    for(auto adj: adjList[node]){
        if(!visited[adj]) topoSort(adj, adjList, visited, res);
    }

    res.push_back(node);
}

void dfs(int node, unordered_map<int, vector<int>> &adjList,
vector<int> &visited, vector<int> &res) {
    visited[node] = 1;
    res.push_back(node);

    for(auto adj: adjList[node]){
        if(!visited[adj]) dfs(adj, adjList, visited, res);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adjList;
    for(auto edge: edges){
        adjList[edge[0]].push_back(edge[1]); //directed
    }

    vector<int> topo;
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i])
            topoSort(i, adjList, visited, topo);
    }
    reverse(topo.begin(), topo.end());

    unordered_map<int, vector<int>> revAdjList;

    for(auto it: adjList){
        for(int i: it.second){
            revAdjList[i].push_back(it.first);
        }
    }

    visited.clear();
    visited.resize(n, 0);
    vector<vector<int>> ans;
    for(auto node: topo){
        if(!visited[node]){
            vector<int> temp;
            dfs(node, revAdjList, visited, temp);
            ans.push_back(temp);
        }
    }

    return ans;
}
```
