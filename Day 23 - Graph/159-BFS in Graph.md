### [BFS in Graph](https://www.codingninjas.com/studio/problems/bfs-in-graph_8230763?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

void bfs(int node, unordered_map<int, set<int>> adjList, 
vector<int> &visited, vector<int> &ans){
  visited[node] = 1;
  queue<int> q;
  q.push(node);

  while(!q.empty()){
    int f = q.front(); q.pop();
    ans.push_back(f);

    for(int adj: adjList[f]){
      if(!visited[adj]){
          visited[adj] = 1;
          q.push(adj);
      }
    }
  }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
  unordered_map<int, set<int>> adjList;
  for(auto edge: edges){
    adjList[edge.first].insert(edge.second);
    adjList[edge.second].insert(edge.first);
  }
  vector<int> ans;
  vector<int> visited(vertex, 0);

  for(int i = 0; i < vertex; i++){
    if(!visited[i]) bfs(i, adjList, visited, ans);
  }
  return ans;
}
```