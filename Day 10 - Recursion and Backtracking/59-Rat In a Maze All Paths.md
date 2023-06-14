### [Rat In a Maze All Paths](https://www.codingninjas.com/codestudio/problems/rat-in-a-maze-all-paths_8230705?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 

bool isSafe(int i, int j, int m, int n, vector<vector<int> > &maze){
  if(i < 0 || j < 0 || i == m || j == n) return false; //out of bounds
  if(maze[i][j] != 1) return false; //not a valid cell
  return true; //safe
}

void f(vector<vector<int>> &maze, vector<vector<int>> &ans, int i, int j){
  
  int m = maze.size(),n = maze[0].size();
  if(i == m-1 && j == n-1){
    vector<int>temp;
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        if(maze[i][j] == 2) temp.push_back(1); //path cell 
        else temp.push_back(0); //blocked cell
      }
    }
    ans.push_back(temp);
    return;
  }

  if(isSafe(i+1, j, m, n, maze)){ //down
    maze[i+1][j] = 2; //path cell
    f(maze, ans, i+1, j); //find the solution for the remaining board
    maze[i+1][j] = 1; //backtrack
  }

  if(isSafe(i-1, j, m, n,maze)){ //up
    maze[i-1][j] = 2;
    f(maze, ans, i-1, j);
    maze[i-1][j] = 1;
  }

  if(isSafe(i, j+1, m, n, maze)){ //right
    maze[i][j+1] = 2;
    f(maze, ans, i, j+1);
    maze[i][j+1] = 1;
  }

  if(isSafe(i,j-1,m,n,maze)){ //left
    maze[i][j-1] = 2;
    f(maze, ans, i, j-1);
    maze[i][j-1] = 1;
  }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  if(n == 1 && maze[0][0] == 1) return {{1}};
  vector<vector<int>> ans;
  maze[0][0] = 2; //path cell as we start from (0, 0)
  f(maze, ans, 0, 0);
  return ans;
}
/* 
TC = O(4^(n*n)) // 4 directions
SC = O(n*n)
*/
```
