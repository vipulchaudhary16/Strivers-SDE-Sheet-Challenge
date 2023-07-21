### [Check Bipartite Graph](https://www.codingninjas.com/studio/problems/check-bipartite-graph_8230761?challengeSlug=striver-sde-challenge&leftPanelTab=0)

### BFS coloring
```cpp
/*
A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color. or no two adjacent vertices are colored with the same color.
*/
#include<bits/stdc++.h>

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	vector<int> colors(n, 0);

	unordered_map<int, vector<int>> adjList;
    for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(edges[i][j]){
				adjList[i].push_back(j);
				adjList[j].push_back(i);
			}
		}
	}

	for(int node = 0; node < n; node++){
		if(colors[node] == 0){
			queue<int> q;
			q.push(node);
			colors[node] = 1;

			while(!q.empty()){
				int curr = q.front();
				q.pop();

				for(int adj: adjList[curr]){
					if(colors[adj] == 0){
						colors[adj] = -colors[curr];
						q.push(adj);
					} else {
						if(colors[adj] != -colors[curr]) return false;
					}
				}
			}
		}
	}

	return true;

}
```