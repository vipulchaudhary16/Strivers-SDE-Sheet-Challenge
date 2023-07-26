### [Subset Sum Equal To K](https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_8230844?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
  if(target == 0) return true; //we have found a subset
  if(ind == 0) return (arr[0] == target); //we have only one element left so we can only make subset if the target is equal to the element
  if(dp[ind][target] != -1) return dp[ind][target];
  
  // we have two choices either we can take the element or we can not take the element
  // if we take the element then we have to check if we can make the subset with the remaining elements and the remaining target
  bool take = target >= arr[ind] ? f(ind-1, target - arr[ind], arr, dp) : false;
  bool notTake = f(ind-1, target, arr, dp); 
  
  return dp[ind][target] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<vector<int>> dp (n, vector<int>(k+1, -1));
  return f(n-1, k, arr, dp);
}
/*
TC = O(n*k)
SC = O(n*k)
*/
```