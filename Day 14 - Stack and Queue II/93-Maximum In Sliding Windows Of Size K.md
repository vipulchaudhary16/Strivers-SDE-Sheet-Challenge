### [Maximum In Sliding Windows Of Size K](https://www.codingninjas.com/studio/problems/maximum-in-sliding-windows-of-size-k_8230772?challengeSlug=striver-sde-challenge&leftPanelTab=0)

### Brute Force Approach
```cpp
#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> res;
    int n = nums.size();
    for(int i = 0; i <= n-k; i++){
        int maxi = nums[i];
        for(int j = i; j < i+k; j++){
            maxi = max(maxi, nums[j]);
        }
        res.push_back(maxi);
    }
    return res;
}
/*
TC = O(n*k)
SC = O(1)
*/
```

### Optimal Approach
```cpp
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int n = nums.size();
    deque<int> dq;
    for(int i = 0; i < n; i++){
      // remove the elements which are out of window
      while(!dq.empty() and dq.front() <= i-k) dq.pop_front();
      // remove the elements which are smaller than current element
      while(!dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
      dq.push_back(i); // push the current element
      if(i >= k-1) res.push_back(nums[dq.front()]) ; // push the front element of deque when window size is reached
    }
    return res;
  }
};
/*
TC = O(n)
SC = O(k)
*/
```
