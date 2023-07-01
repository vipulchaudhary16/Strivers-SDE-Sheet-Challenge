### [Maximum of minimum for every window size](https://www.codingninjas.com/studio/problems/maximum-of-minimum-for-every-window-size_8230783?challengeSlug=striver-sde-challenge&leftPanelTab=0)

### Brute force
```cpp
#include <bits/stdc++.h> 

int maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
      // remove the elements which are out of window
      while(!dq.empty() and dq.front() <= i-k)  dq.pop_front();
      // remove the elements which are smaller than current element
      while(!dq.empty() and nums[dq.back()] > nums[i]) dq.pop_back();
      dq.push_back(i); // push the current element
      if(i >= k-1) // push the front element of deque when window size is reached
      {
        maxi = max(maxi, nums[dq.front()]);
      }
    }
    return maxi;
  }

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans;
    for(int k = 1; k <= n; k++){
        ans.push_back(maxSlidingWindow(a, k));
    }
    return ans;
}
/*
TC = O(n^2)
SC = O(k)
*/
```
#### Optimal Approach

### [Maximum of minimum for every window size(GFG)](https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article) 

```cpp
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int a[], int n)
    {
        vector<int> leftSmaller(n, -1), rightSmaller(n, n);
        stack<int> ls, rs;
        
        // Calculate the indices of the nearest smaller elements on the left side
        for (int i = 0; i < n; i++) {
            while (!ls.empty() && a[ls.top()] >= a[i])
                ls.pop();
            if (!ls.empty())
                leftSmaller[i] = ls.top();
            ls.push(i);
        }
        
        // Calculate the indices of the nearest smaller elements on the right side
        for (int i = n - 1; i >= 0; i--) {
            while (!rs.empty() && a[rs.top()] >= a[i])
                rs.pop();
            if (!rs.empty())
                rightSmaller[i] = rs.top();
            rs.push(i);
        }
        // Fill in any missing values in the result vector by taking the maximum from the right

        vector<int> res(n + 1, 0);  // +1 to include window size 1
        for (int i = 0; i < n; i++) {
            int windowSize = rightSmaller[i] - leftSmaller[i] - 1;
            res[windowSize] = max(res[windowSize], a[i]);
        }
        
        // Fill in any missing values in the result vector by taking the maximum from the right
        for (int i = n - 1; i >= 1; i--)
            res[i] = max(res[i], res[i + 1]);
        
        // Remove the unused value at index 0
        res.erase(res.begin());
        
        return res;
    }

};

```