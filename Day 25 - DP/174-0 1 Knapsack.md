### [0 1 Knapsack](https://www.codingninjas.com/studio/problems/0-1-knapsack_8230801?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
int f(int ind, int w, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
    if(ind == 0){
        if(w >= weight[0]) return value[0];
        return 0;
    }
    
    if(dp[ind][w] != -1) return dp[ind][w];
    
    int notTake = f(ind-1, w, weight, value, dp);
    int take =  weight[ind] > w ? -1e8 : value[ind] + f(ind-1, w - weight[ind], weight, value, dp);
    
    return dp[ind][w] = max(take, notTake);
    
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	  vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return f(n-1, w, weights, values, dp);
}
```