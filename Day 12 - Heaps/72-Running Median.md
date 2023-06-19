### [Running Median](https://www.codingninjas.com/studio/problems/running-median_8230682?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>

void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap; // max heap for the left half
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap for the right half

    for(int i = 0; i < n; i++){
      // if the max heap is empty or the current element is less than the top element of the max heap, push it into the max heap
      if(maxHeap.empty() || maxHeap.top() >= arr[i])
          maxHeap.push(arr[i]);
      // else push it into the min heap
      else minHeap.push(arr[i]);

      // if the size of the max heap is greater than the size of the min heap by more than 1, pop the top element from the max heap and push it into the min heap
      if(maxHeap.size() > minHeap.size() + 1){
          minHeap.push(maxHeap.top());
          maxHeap.pop();
      // else if the size of the min heap is greater than the size of the max heap by more than 1, pop the top element from the min heap and push it into the max heap
      } else if (maxHeap.size() < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }

      // if the size of the max heap is greater than the size of the min heap, print the top element of the max heap
      if(minHeap.size() < maxHeap.size())
          cout<<maxHeap.top()<<" ";
      else
          cout<<(minHeap.top() + maxHeap.top())/2<<" ";
        
    }
}
/*
TC: O(nlogn)
SC: O(n)
*/
```