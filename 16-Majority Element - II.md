### [Majority Element - II](https://www.codingninjas.com/codestudio/problems/majority-element-ii_8230738?challengeSlug=striver-sde-challenge)

#### Brute Force
```cpp
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, int> mp; // number, count

    for(auto a: arr) mp[a]++; // count frequency

    for(auto it: mp){
        if(it.second > (n/3)) ans.push_back(it.first); // if frequency is greater than n/3, push it to ans
    }

    return ans;
    /*
    TC: O(n)
    SC: O(n)
    */

}
```

#### Optimized
```cpp
#include <bits/stdc++.h>

// Boyer-Moore Voting Algorithm (n/3)
vector<int> majorityElementII(vector<int> &arr)
{
  // there can be at most 2 elements with frequency greater than n/3
  int ans1, ans2, count1=0, count2=0, n = arr.size();;

  for(auto a: arr){
    if(a == ans1) count1++;
    else if(a == ans2) count2++;
    else {
      if(count1 == 0){
        ans1 = a;
        count1=1;
      } else if(count2 == 0){
        ans2 = a;
        count2 = 1;
      }  
      else {
        count1--;
        count2--;
      }
    }
  }

  count1 = count2 = 0;

  for(auto a: arr){
    if(a == ans1) count1++;
    else if(a == ans2) count2++;
  }

  vector<int> ans;
  if(count1 > n/3) ans.push_back(ans1);
  if(count2 > n/3) ans.push_back(ans2);

  return ans;

}
```