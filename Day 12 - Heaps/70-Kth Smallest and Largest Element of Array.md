### [Kth Smallest and Largest Element of Array](https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_8230829?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k){

	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;

	for(int i = 0; i < n; i++){
		maxHeap.push(arr[i]);
		minHeap.push(arr[i]);
		if(maxHeap.size() > k) maxHeap.pop();
		if(minHeap.size() > k) minHeap.pop();
	}

	return {maxHeap.top(), minHeap.top()};

}
```