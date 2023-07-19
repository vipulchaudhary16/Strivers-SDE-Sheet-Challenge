### [Kth largest element in the unsorted array](https://www.codingninjas.com/studio/problems/kth-largest-element-in-the-unsorted-array_8230740?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int ,vector<int>,greater<int>>pq;
	for(auto ele:arr){
		pq.push(ele);
		if(pq.size()>K)pq.pop();
	}
	return pq.top();
}
```