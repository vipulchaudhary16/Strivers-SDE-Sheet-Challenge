### [Detect Cycle In A Directed Graph](https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_8230794?challengeSlug=striver-sde-challenge&leftPanelTab=0)

### DFS
```cpp
#include<bits/stdc++.h>

int detect(int node, unordered_map<int, vector<int>> &adjList, 
vector<int> &visited, vector<int> &pathVisited){
    visited[node] = 1;
    pathVisited[node] = 1;
    
    for(int adj: adjList[node]){
        if(!visited[adj]){
            if(detect(adj, adjList, visited, pathVisited)) 
              return 1;
        } else if(pathVisited[adj]) return 1;
    }

    pathVisited[node] = 0;
    return 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, vector<int>> adjList;
    for(auto edge: edges){
        adjList[edge.first].push_back(edge.second);
    }
    vector<int> visited(n+1, 0), pathVisited(n+1, 0);

    for(int i = 1; i < n; i++){
        if(!visited[i]){
            if(detect(i, adjList, visited, pathVisited))
                return 1;
        }
    }

    return 0;
}
```

### BFS
```cpp
#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, vector<int>> adjList;
    for(auto edge: edges){
        adjList[edge.first].push_back(edge.second);
    }
    
    vector<int> inDeg(n+1, 0);
    queue<int> q;

    for(auto edge: edges){
        inDeg[edge.second]++;
    }

    for(int i = 1; i <= n; i++){
        if(inDeg[i] == 0) q.push(i);
    }

    int topos = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        topos++;
        
        for(int adj: adjList[top]){
            inDeg[adj]--;
            if(inDeg[adj] == 0) q.push(adj);
        }
    }

    return topos != n;
}
```