### [Bellman Ford](https://www.codingninjas.com/studio/problems/bellman-ford_8230845?challengeSlug=striver-sde-challenge)

```cpp
/*
* Dijkstra's algorithm fails when there are negative weight edges in the graph.
* There the Bellman Ford algorithm comes into play.

* You need to relax all the edges n-1 times, where n is the number of vertices in the graph. 
* Relaxing means updating the distance of all the vertices from the source vertex.
  eg: dist[v] = min(dist[v], dist[u] + weight(u, v)) where u is the parent of v or the vertex from which we are reaching v.

* But why n-1 times?
- So if we take worst case, then in each iteration we are updating the one vertex's distance from the source vertex only.
- In worst case a path from source vertex to any other vertex can have at most n-1 edges.

* How to detect negative weight cycle?
- If after n-1 iterations, if we are able to relax any edge, then there is a negative weight cycle in the graph.
*/

#include <bits/stdc++.h> 
int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1000000000);
    dist[src] = 0;

    for(int i = 1; i <= n-1; i++){
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != 1000000000){ // if dist[u] is not INT_MAX then only we can relax the edge
                dist[v] = min(dist[v], dist[u] + wt);
            }
        }
    }

    return dist[dest];
}
/*
TC: O(n*m) where n is the number of vertices and m is the number of edges
SC: O(n)
*/
```