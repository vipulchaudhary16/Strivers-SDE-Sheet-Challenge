### [Best Time to Buy and Sell Stock](https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_8230746?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices){
    int ans = 0, minPrice = prices[0]; // minPrice to store the minimum price till now

    for(auto price: prices){
        int currProfit = price - minPrice; //
        ans = max(ans, currProfit); // update ans if currProfit is greater than ans
        minPrice = min(minPrice, price);
    }

    return ans;
}
```