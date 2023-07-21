### [Find Number Of Islands](https://www.codingninjas.com/studio/problems/find-number-of-islands_8230692?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>

void bfs(int row, int col, int n, int m, int ** arr, vector<vector<int>> &visited){
   visited[row][col] = 1;
   queue<pair<int, int>> q;
   q.push({row, col});

   while(!q.empty()){
      int currRow = q.front().first;
      int currCol = q.front().second;
      q.pop();

      for(int drow = -1; drow <= 1; drow++){
         for(int dcol = -1; dcol <= 1; dcol++){
            int nrow = currRow + drow;
            int ncol = currCol + dcol;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
               && arr[nrow][ncol] == 1 && !visited[nrow][ncol]){
                  visited[nrow][ncol] = 1;
                  q.push({nrow, ncol});
               }
         }
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<int>> visited(n, vector<int>(m, 0));

   int ans = 0;

   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(!visited[i][j] && arr[i][j] == 1){
            ans++;
            bfs(i, j, n, m, arr, visited);
         }
      }
   }

   return ans;
}

```

#### DFS

```cpp
#include<bits/stdc++.h>

void dfs(int row, int col, int n, int m, int ** arr, vector<vector<int>> &visited){
   visited[row][col] = 1;
   for(int drow = -1; drow <= 1; drow++){
      for(int dcol = -1; dcol <= 1; dcol++){
         int nrow = row + drow;
         int ncol = col + dcol;

         if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && arr[nrow][ncol] == 1 && !visited[nrow][ncol]){
               dfs(nrow, ncol, n, m, arr, visited);
         }
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<int>> visited(n, vector<int>(m, 0));

   int ans = 0;

   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(!visited[i][j] && arr[i][j] == 1){
            ans++;
            dfs(i, j, n, m, arr, visited);
         }
      }
   }

   return ans;
}

```