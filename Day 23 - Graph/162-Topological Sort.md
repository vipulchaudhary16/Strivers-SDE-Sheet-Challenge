### [Topological Sort](https://www.codingninjas.com/studio/problems/topological-sort_8230784?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

void dfsTopo(int node, unordered_map<int, vector<int>> &adjList, vector<int> &visited, stack<int> &st){
    visited[node] = 1;

    for(int adj: adjList[node]){
        if(!visited[adj]){
            dfsTopo(adj, adjList, visited, st);
        }
    }

    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adjList;
    for(auto edge: edges){
        adjList[edge[0]].push_back(edge[1]);
    }

    vector<int> visited(v, 0);
    stack<int> st;
    for(int i = 0; i < v; i++){
        if(!visited[i]) dfsTopo(i, adjList, visited, st);
    }

    vector<int> res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}
```

### Without using stack

```cpp
#include <bits/stdc++.h> 

void dfsTopo(int node, unordered_map<int, vector<int>> &adjList, vector<int> &visited, vector<int> &st){
    visited[node] = 1;

    for(int adj: adjList[node]){
        if(!visited[adj]){
            dfsTopo(adj, adjList, visited, st);
        }
    }

    st.push_back(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adjList;
    for(auto edge: edges){
        adjList[edge[0]].push_back(edge[1]);
    }

    vector<int> visited(v, 0);
    vector<int> res;
    for(int i = 0; i < v; i++){
        if(!visited[i]) dfsTopo(i, adjList, visited, res);
    }

    reverse(res.begin(), res.end());
    return res;
}
```

#### Kahn's Algorithm

```cpp
#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adjList;
    for(auto edge: edges){
        adjList[edge[0]].push_back(edge[1]);
    }

    vector<int> inDeg(v, 0);
    queue<int> q;

    for(auto edge: edges){
        inDeg[edge[1]]++;
    }

    for(int i = 0; i < v; i++){
        if(inDeg[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        topo.push_back(top);
        
        for(int adj: adjList[top]){
            inDeg[adj]--;
            if(inDeg[adj] == 0) q.push(adj);
        }
    }

    return topo;
    
}
```