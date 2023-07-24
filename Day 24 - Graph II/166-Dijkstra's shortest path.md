### [Dijkstra's shortest path](https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_8230755?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

vector<int> dijkstra(vector<vector<int>> &vec, int v, int e, int source) {
    vector<int> dist(v,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    unordered_map<int, vector<pair<int, int>>> adjList; // {node -> {neighbor, weight}}

    for(auto edge: vec){
        adjList[edge[0]].push_back({edge[1], edge[2]});
        adjList[edge[1]].push_back({edge[0], edge[2]});
    }

    pq.push({0, source});
    dist[source] = 0;

    while(!pq.empty()){
        int currentNode = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        for(auto adj: adjList[currentNode]){
            if(dist[adj.first] > currentDistance + adj.second){
                dist[adj.first] = currentDistance + adj.second;
                pq.push({dist[adj.first], adj.first});
            }
        }
    }

    return dist;
}
/*
TC: O(nlogn + m) where n is the number of vertices and m is the number of edges
SC: O(n)
*/
```