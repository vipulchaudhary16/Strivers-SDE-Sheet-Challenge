### [Count Subarrays with Given XOR](https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_8230830?challengeSlug=striver-sde-challenge)

#### Brute force

```cpp
#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int count=0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int xor_ = 0;
            // xor of subarray from i to j
            for(int k = i; k <= j; k++){
                xor_ ^= arr[k];
            }
            if(xor_ == x) count++;
        }
    }
    return count;
    /*
    Time Complexity: O(n^3)
    Space Complexity: O(1)
    */
}
```

#### Optimized

```cpp
#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int count=0;
    for(int i = 0; i < n; i++){
        int xor_ = 0;
        for(int j = i; j < n; j++){
          // xor of subarray from i to j, eventually xor_ will be xor of subarray from i to j, for all subarrays
          xor_ ^= arr[j];
          if(xor_ == x) count++;
        }
    }
    return count;
    /*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
}
```

#### Optimal

```cpp
#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    int n = arr.size();
    int count=0, xr = 0;
    unordered_map<int, int> mp;
    mp[0]=1; 
    
    for(int i = 0; i < n; i++){
        xr ^= arr[i];
        int x = xr ^ k;
        if(mp.count(x)) count += mp[x];
        mp[xr]++;
    }
    return count;
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
}
```