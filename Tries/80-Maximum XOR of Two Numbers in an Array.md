### [Maximum XOR of Two Numbers in an Array](https://www.codingninjas.com/studio/problems/maximum-xor-of-two-numbers-in-an-array_8230852?challengeSlug=striver-sde-challenge&leftPanelTab=0)

- [YT](https://www.youtube.com/watch?v=EIhAwfHubE8&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=6)

- [LeetCode](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) 


#### Brute force (TLE)

```cpp
#include <bits/stdc++.h>
int maximumXor(vector<int> A)
{
  int maxi = 0, n = A.size();
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      maxi = max(maxi, A[i]^A[j]);
    }
  }
  return maxi;
/*
TC: O(n^2)
SC: O(1)
*/
}
```
