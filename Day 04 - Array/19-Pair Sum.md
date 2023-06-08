### [Pair Sum](https://www.codingninjas.com/codestudio/problems/pair-sum_8230699?challengeSlug=striver-sde-challenge)


#### Optimal Approach
```cpp
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
  vector<vector<int>> ans;
  unordered_map<int,int>mp; // to store the frequency of elements

  for(int i=0;i<arr.size();i++){
    if(mp[s-arr[i]]){ // if the difference is present in the map
        int val=mp[s-arr[i]]; // get the frequency of the difference
        vector<int> temp;
        while(val--){ // push the pairs in the ans vector
          temp.push_back(min(arr[i],s-arr[i]));
          temp.push_back(max(arr[i],s-arr[i]));
          ans.push_back(temp);
        }
    }
    mp[arr[i]]++; // increase the frequency of the element
  }
  sort(ans.begin(),ans.end()); // sort the ans vector
  return ans;
  /*
  Time Complexity: O(n)
  Space Complexity: O(n)
  */
}
```

### [Two Sum](https://leetcode.com/problems/two-sum/)

#### Brute force approach

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> v;
      for(int i=0 ; i<nums.size() ; i++){
          for(int j=i+1 ; j<nums.size() ; j++){
              if(nums[i]+nums[j]==target){ // if the sum is equal to target
                  v.clear();
                  v.push_back(i);
                  v.push_back(j);
                  break;
              }
          }
      }
      return v;
    }
    /*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
};
```

#### Optimal using hashmap

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n = nums.size();
      unordered_map<int, int> mp; // to store the index of elements
      for(int i = 0; i < n; i++) mp[nums[i]] = i; // store the index of elements

      for(int i = 0; i < n; i++){
          int curr = nums[i]; // current element
          int req = target - curr; // required element
          if(mp.count(req) and mp[req] != i) return {i, mp[req]}; // if the required element is present in the map and it is not the same element
      }

      return {-1, -1};
    }
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
};
```

#### Optimal using two pointer

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
      sort(arr.begin(), arr.end()); // sort the array
      int left = 0, right = arr.size() - 1; // two pointers
      while (left < right) { // while the two pointers don't cross each other
          int sum = arr[left] + arr[right]; // calculate the sum
          if (sum == target) {
              return {left, right}; // if the sum is equal to target return the indices
          }
          else if (sum < target) left++; // if the sum is less than target increase the left pointer
          else right--; // if the sum is greater than target decrease the right pointer
      }
      return {-1, -1};
    }
    /*
    Time Complexity: O(nlogn)
    Space Complexity: O(1)
    */
};
```
