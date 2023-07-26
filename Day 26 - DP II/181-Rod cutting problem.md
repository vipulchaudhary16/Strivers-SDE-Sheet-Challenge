### [Rod cutting problem](https://www.codingninjas.com/studio/problems/rod-cutting-problem_8230727?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>

int solve(int ind, int n, vector<int> &price, vector<vector<int>> &dp){
    if(ind == 0){
        return (n * price[0]); //here we have rod length of 1
    }
    
    if(dp[ind][n] != -1) return dp[ind][n]; 
    
    int notTake = solve(ind-1, n, price, dp);
    int take = -1e9;
    // if we take the current length of rod then we have to cut it into pieces of length 1 to ind
    if(ind + 1 <= n) take = price[ind] + solve(ind, n - (ind+1), price, dp) ;
    
    return dp[ind][n] = max(take, notTake);
}


int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
  return solve(n-1, n, price, dp);
}
/*
TC = O(n*n)
SC = O(n*n)
*/

```