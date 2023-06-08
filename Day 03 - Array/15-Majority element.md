### [Majority element](https://www.codingninjas.com/codestudio/problems/day-6-majority-element_8230731?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
  int ans, count = 0;

  // Moore's Voting Algorithm
  for(int i=0;i<n;i++)
  {
      // if count is 0, then set ans to current element
      if(count == 0){
          ans = arr[i];
          count = 1;
      } else if(ans==arr[i]) // if current element is equal to ans, then increment count
        count++;
      else
        count--;
  }

  // check if ans is majority element
  count=0;
  for(int i=0;i<n;i++)
  {
      if(ans==arr[i])
          count++;
  }

  return count > n/2 ? ans : -1;

  /*
  TC: O(n)
  SC: O(1)
  */
}
```
