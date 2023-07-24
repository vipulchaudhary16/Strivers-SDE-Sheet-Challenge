### [Floyd Warshall](https://www.codingninjas.com/studio/problems/floyd-warshall_8230846?challengeSlug=striver-sde-challenge)

```cpp
/*
* Floyd Warshall algorithm is used to find the shortest distance between all pairs of vertices in a graph.
* It is multiple source shortest path algorithm.

* It is a dynamic programming approach.
* We go via all the vertices and check if the distance between the current vertex and the other vertex is less than the distance between the current vertex and the other vertex via the current vertex.
*/

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    int cost[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cost[i][j]=1e9;
            if(i == j) cost[i][j] = 0;
        }
    }

    for(auto it:edges)
    {
        int u = it[0]-1;
        int v = it[1]-1;
        int wt = it[2];
        cost[u][v] = wt;
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0 ;j<n; j++)
            {
                if(cost[i][k] != 1e9 and cost[k][j] != 1e9){
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }   
            }
        }
    }

    return cost[src-1][dest-1];
}
```