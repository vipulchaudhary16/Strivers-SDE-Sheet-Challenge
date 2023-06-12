### [Find Minimum Number Of Coins](https://www.codingninjas.com/codestudio/problems/find-minimum-number-of-coins_8230766?challengeSlug=striver-sde-challenge&leftPanelTab=0)


```cpp
#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
  int coins[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; // all possible coins
  int ans = 0; //answer

  for(int i = 8; i >= 0; i--){
    while(coins[i] <= amount){ //while coin is less than or equal to amount, we can use it
      amount -= coins[i];
      ans++;
    }
  }

  return ans;
}

```