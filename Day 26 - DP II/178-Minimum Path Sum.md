### [Minimum Path Sum](https://www.codingninjas.com/studio/problems/minimum-path-sum_8230791?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
int f(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
    if(i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j]; //base case for last cell
    if(i >= grid.size() || j >= grid[0].size()) return 1e9; //base case for invalid index
    
    if(dp[i][j] != -1) return dp[i][j]; //if already calculated

    int down = grid[i][j] + f(grid,i+1,j,dp); //going down
    int right = grid[i][j] + f(grid,i,j+1,dp); //going right
    return dp[i][j] = min(down,right); //storing the minimum of both
}
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    return f(grid,0,0,dp);
}
/*
TC = O(n*m)
SC = O(n*m)
*/
```