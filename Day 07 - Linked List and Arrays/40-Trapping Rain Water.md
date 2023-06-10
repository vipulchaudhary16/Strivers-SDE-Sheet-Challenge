### [Trapping Rain Water](https://www.codingninjas.com/codestudio/problems/trapping-rain-water_8230693?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    vector<long> preMax(n, 0), sufMax(n,0); //max before ith and max after ith index
    
    preMax[0] = arr[0];
    for(int i = 1; i < n; i++)preMax[i] = max(preMax[i-1], arr[i]);

    sufMax[n-1] = arr[n-1];
    for(int i = n - 2; i >=0; i--)sufMax[i] = max(sufMax[i+1], arr[i]);

    int ans = 0;
    //ans = ans + min(max_before_i, max_after_i) - current height
    for(int i = 0; i < n; i++) ans += (min(preMax[i], sufMax[i]) - arr[i]);
    
    return ans;
    /*
    TC: O(3N)
    SC: (2N)
    */
}
```

```cpp
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long l = 0, r = n-1, lMax = 0, rMax=0, ans = 0;

    while(l <= r){
        if(arr[l] <= arr[r]){
            if(arr[l] > lMax) lMax = arr[l];
            else ans += (lMax - arr[l]);
            l++;
        } else {
            if(arr[r] > rMax) rMax = arr[r];
            else ans += (rMax - arr[r]);
            r--;
        }
    }

    return ans;
    /*
    TC: O(N)
    SC: O(1)
    */
}
```
