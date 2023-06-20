### [Merge K Sorted Arrays](https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_8230770?challengeSlug=striver-sde-challenge)

#### Brute force
```cpp
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    for(int i = 0; i < kArrays.size(); i++){
        for(int j = 0; j < kArrays[i].size(); j++){
            ans.push_back(kArrays[i][j]); // O(nk)
        }
    }
    sort(ans.begin(), ans.end()); // O(nklognk)
    return ans;
}
/*
TC: O(nk + nlogn)
SC: O(n)
*/
```

#### Using Min Heap
```cpp
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < kArrays.size(); i++){
        for(int j = 0; j < kArrays[i].size(); j++){
            minHeap.push(kArrays[i][j]);
        }
    }

    while(!minHeap.empty()){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return ans;
}
/*
TC: O(lognk + nk)
SC: O(nk)
*/
```

#### Using multiset
```cpp
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    multiset<int> s; // multiset is a BST
    vector<int> ans; 
    for(auto ele:kArrays){
        for(auto el:ele) s.insert(el);
    }
    for(auto ele:s) ans.push_back(ele);
    return ans;
}
/*
TC: O(lognk + nk)
SC: O(nk)
*/
```

