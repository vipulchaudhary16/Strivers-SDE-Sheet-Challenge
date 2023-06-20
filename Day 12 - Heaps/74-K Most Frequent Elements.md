### [K Most Frequent Elements](https://www.codingninjas.com/studio/problems/k-most-frequent-elements_8230853?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
  unordered_map<int, int> freq; // {element, frequency}
  for(auto ele:arr) freq[ele]++;

  priority_queue<pair<int, int>> maxHeap; // {frequency, element}
  for(auto it:freq) maxHeap.push({it.second, it.first});

  vector<int> ans;
  while(k--){
      ans.push_back(maxHeap.top().second);
      maxHeap.pop();
  }
  sort(ans.begin(), ans.end()); // O(klogk)
  return ans;
}
/*
TC: O(nlogn + klogk)
SC: O(n)
*/
```