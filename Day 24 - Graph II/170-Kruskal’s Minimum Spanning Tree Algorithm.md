### [Kruskal’s Minimum Spanning Tree Algorithm](https://www.codingninjas.com/studio/problems/kruskal-s-minimum-spanning-tree-algorithm_8230804?challengeSlug=striver-sde-challenge)


#### Disjoint Set
```cpp
/*
Disjoint set: It is a data structure used to detect component region of any node of a graph

It has two functions:
1. FindParent(node) : find parent of given node
2. Union(u, v): it combines two node in one component
  - Union can be done using rank or size

* Union by rank
- We required rank arr and parent arr
- rank = {0};
- rank = {i/ i is index}

union(u,v):
  - find ultimate parent of u and v
  - find rank of them (ultimate parents)
  - connect smaller rank to larger rank always

* Path compression: It is a technique to reduce the height of tree, so that findParent() can be done in O(1) time

* Time complexity: O(4*alpha) ~= O(1)  // alpha is inverse ackermann function
* Space complexity: O(n)

*/
class DisjointSet {
  vector<int> parent;
  vector<int> rank;
  int n;
public:
  DisjointSet(int n) {
    this->n = n;
    parent.resize(n);
    rank.resize(n);
    for(int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int findParent(int node) {
    if(node == parent[node]) return node;
    // path compression technique
    return parent[node] = findParent(parent[node]);
  }

  void union(int u, int v) {
    int uParent = findParent(u);
    int vParent = findParent(v);
    if(uParent == vParent) return; // already in same component

    // smaller rank to larger rank
    if(rank[uParent] < rank[vParent]) {
      parent[uParent] = vParent;
    } else if(rank[uParent] > rank[vParent]) {
      parent[vParent] = uParent;
    } else {
      parent[vParent] = uParent;
      rank[uParent]++; // increase rank of uParent by 1 as it is connected to vParent
    }
  }

  void unionBySize(int u, int v) {
    int uParent = findParent(u);
    int vParent = findParent(v);
    if(uParent == vParent) return; // already in same component

    // smaller size to larger size
    if(size[uParent] < size[vParent]) {
      parent[uParent] = vParent;
      size[vParent] += size[uParent];
    } else {
      parent[vParent] = uParent;
      size[uParent] += size[vParent];
    }
  }
};
/*
But why smaller rank to larger rank?
- Because we want to reduce the height of tree
- If we connect larger rank to smaller rank, then height of tree will increase
- If we connect smaller rank to larger rank, then height of tree will not increase
*/
```

#### Kruskal’s Minimum Spanning Tree Algorithm
```cpp
/*
Algorithm:
1. Sort all edges in increasing order of their weight
2. Pick smallest edge and check if it forms a cycle with the spanning tree formed so far
  - If cycle is not formed, include this edge
  - Else, discard it
*/
#include <bits/stdc++.h> 

class disjoint{
    vector<int> size,parent;
    public:
     disjoint(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<n;i++){ 
            parent[i]=i;
        }
    }

    int uparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=uparent(parent[node]);
    }

    void unionbysize(int u,int v){
        int ulp_u=uparent(u);
        int ulp_v=uparent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    vector<pair<int,pair<int,int>>> edges;
        for(auto it: graph){
            int wt=it[2];
            int adjnode=it[1];
            int node=it[0];
            edges.push_back({wt,{node,adjnode}});
        }

    disjoint ds(n);
    sort(edges.begin(),edges.end());
    
	int sum=0;
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.uparent(u)!=ds.uparent(v)){
            sum+=wt;
            ds.unionbysize(u,v);
        }
    }

    return sum;
}
```