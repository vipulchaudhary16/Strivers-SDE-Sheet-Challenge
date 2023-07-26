### [Ways To Make Coin Change](https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_8230691?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>

long f(int ind, int tar, int * nums,  vector<vector<long>> &dp){
  if(ind == 0){
    // here we have only one coin left so we can only make change if the target is multiple of the coin value
    if(tar % nums[0] == 0) return 1;
    return 0;
  }
  
  if(dp[ind][tar] != -1) return dp[ind][tar];
  
  long notTake = f(ind-1, tar, nums, dp); // not taking the coin
  long take = 0; // taking the coin
  if(tar >= nums[ind]){ // if the target is greater than the coin value then only we can take the coin
    take = f(ind, tar - nums[ind], nums, dp);
  }
  
  return dp[ind][tar] = take + notTake; // total ways will be sum of both the ways
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
  vector<vector<long>> dp(n, vector<long> (value+1, -1));
  return f(n-1, value, denominations, dp);
}
/*
TC = O(n*value)
SC = O(n*value)
*/
```