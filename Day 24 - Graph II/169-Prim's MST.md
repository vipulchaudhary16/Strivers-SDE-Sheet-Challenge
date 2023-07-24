### [Prim's MST](https://www.codingninjas.com/studio/problems/prim-s-mst_8230809?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
/*
MST: Minimum Spanning Tree, is a tree in a graph which connects all the vertices with minimum cost.
Prim's algorithm is used to find the MST of a graph.
It is a greedy algorithm.
It is a single source shortest path algorithm.
*/
#include <bits/stdc++.h> 

struct CustomComparator {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0]; // Compare based on the first element of each vector (minimum value).
    }
};

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, vector<pair<int, int>>> adjList;
    for(auto it: g){
        adjList[it.first.first].push_back({it.first.second, it.second});
        adjList[it.first.second].push_back({it.first.first, it.second});
    }

    priority_queue<vector<int>, vector<vector<int>>, CustomComparator> pq;
    pq.push({0, 1, -1}); //{weight, node, parent}
    vector<int> visited(n+1, 0);
    vector<pair<pair<int, int>, int>> mst;

    while(!pq.empty()){
        auto v = pq.top(); 
        pq.pop();
        int node = v[1];
        int wt = v[0];
        int parent = v[2];

        if(visited[node]) continue;

        visited[node] = 1;
        if(parent != -1)
            mst.push_back({{parent, node}, wt});
        
        for(auto adj: adjList[node]){
            int adjNode = adj.first;
            int adjNodeWt = adj.second;
            if(!visited[adjNode]){
                pq.push({adjNodeWt, adjNode, node});
            }
        }
    }

    return mst;
}

```