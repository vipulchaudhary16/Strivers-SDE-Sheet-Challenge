### [Maximum Subarray Sum](https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_8230694?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long ans = INT_MIN, curr = 0; // ans to store the final answer, curr to store the current sum
    for(int i = 0; i < n; i++){
        curr += arr[i];
               
        if(curr < 0){ // if curr is negative, we reset it to 0
            curr = 0;
        } 

        if(curr > ans){ // if curr is greater than ans, we update ans
            ans = curr;
        }
    }

    return ans;
}

//-7 -8 -16 -4 -8 -5 -7 -11 -10 -12 -4 -6 -4 -16 -10 
```