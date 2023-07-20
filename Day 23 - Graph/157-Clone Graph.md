### [Clone Graph](https://www.codingninjas.com/studio/problems/clone-graph_8230812?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
void dfs(graphNode * node, graphNode *copy, unordered_map<int, graphNode*> &visited){
	visited[copy->data] = copy;

	for(auto adj: node->neighbours){
		if(visited.count(adj->data) == 0){
			graphNode * adjCopy = new graphNode(adj->data);
			copy->neighbours.push_back(adjCopy);
			dfs(adj, adjCopy, visited);
		} else copy->neighbours.push_back(visited[adj->data]);
	}
}

graphNode *cloneGraph(graphNode *node)
{
	unordered_map<int, graphNode*> visited;
	graphNode * copy = new graphNode(node->data);
	visited[copy->data] = copy;

	for(auto adj: node->neighbours){
		if(visited.count(adj->data) == 0){
			graphNode * adjCopy = new graphNode(adj->data);
			copy->neighbours.push_back(adjCopy);
			dfs(adj, adjCopy, visited);
		} else copy->neighbours.push_back(visited[adj->data]);
	}

	return copy;
}
/*
TC: O(E*V)
SC: O(N)
*/
```