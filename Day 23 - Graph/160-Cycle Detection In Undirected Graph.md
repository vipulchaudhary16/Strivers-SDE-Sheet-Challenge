### [Cycle Detection In Undirected Graph](https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_8230798?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### BFS

```cpp
#include<bits/stdc++.h>

bool detect(int node, unordered_map<int, vector<int>> adjList, vector<int> &visited){
    visited[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, -1});

    while(!q.empty()){
        int currNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adj: adjList[currNode]){
            if(!visited[adj]){
                visited[adj] = 1;
                q.push({adj, currNode});
            } else if(adj != parent) return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, vector<int>> adjList;
    for(auto edge: edges){
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    vector<int> visited(n+1, 0);

    for(int i = 1; i < n; i++){
        if(!visited[i]){
            if(detect(i, adjList, visited))
                return "Yes";
        }
    }

    return "No";
}

```

### DFS

```cpp
#include<bits/stdc++.h>

bool detect(int node, int parent, unordered_map<int, vector<int>> adjList, vector<int> &visited){
    visited[node] = 1;
    
    for(int adj: adjList[node]){
        if(!visited[adj]){
            if(detect(adj, node, adjList, visited)) return true;
        } else if(adj != parent) return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, vector<int>> adjList;
    for(auto edge: edges){
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    vector<int> visited(n+1, 0);

    for(int i = 1; i < n; i++){
        if(!visited[i]){
            if(detect(i, -1, adjList, visited))
                return "Yes";
        }
    }

    return "No";
}

```