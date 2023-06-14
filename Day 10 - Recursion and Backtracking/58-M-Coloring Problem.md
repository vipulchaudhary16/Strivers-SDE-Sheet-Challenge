### [M-Coloring Problem](https://www.codingninjas.com/codestudio/problems/m-coloring-problem_8230777?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

bool isSafe(int node, int color, vector<int> &colors, vector<vector<int>> &mat){
    for(int i = 0; i < mat.size(); i++){
        if(i != node //not the same node
        and mat[i][node] == 1  //connected
        and colors[i] == color) //same color
          return false;
    }
    return true;
}

bool f(int node, vector<int> &color, vector<vector<int>> &mat, int m){
    if(node == mat.size()){
        return true; //all nodes are colored
    }

    //try all colors
    for(int i = 1; i <= m; i++){
        if(isSafe(node, i, color, mat)){ //if it is safe to color the node with color i
            color[node] = i; //color the node
            if(f(node+1, color, mat, m)) return true; //find the solution for the remaining graph
            else color[node] = 0; //backtrack
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    vector<int> colors(mat.size(), 0);
    return f(0, colors, mat, m) ? "YES" : "NO";
}
/*
TC = O(m^n)
SC = O(n)
*/
```
