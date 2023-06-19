### [K Max Sum Combinations](https://www.codingninjas.com/studio/problems/day-29-k-max-sum-combinations_8230768?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k) {
  // Sort the arrays in descending order.
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());

  // Create a vector to store the results.
  vector<int> result;

  // Create a set to store the visited pairs.
  set<pair<int, int>> vis;

  // Create a priority queue to store the maximum sum combinations.
  priority_queue<pair<int, pair<int, int>>> maxHeap;

  // Push the first element of each array into the priority queue.
  maxHeap.push({a[0] + b[0], {0, 0}});

  // Iterate for `k` times.
  for (int i = 0; i < k; i++) {
    // Get the top element from the priority queue.
    auto top = maxHeap.top();
    maxHeap.pop();

    // Add the top element to the results vector.
    result.push_back(top.first);

    // Get the indices of the elements in the top element.
    int prev_a = top.second.first;
    int prev_b = top.second.second;

    // If the next element in `a` is not visited, push it into the priority queue.
    if (prev_a + 1 < n && vis.count({prev_a + 1, prev_b}) == 0) {
      maxHeap.push({a[prev_a + 1] + b[prev_b], {prev_a + 1, prev_b}});
      vis.insert({prev_a + 1, prev_b});
    }

    // If the next element in `b` is not visited, push it into the priority queue.
    if (prev_b + 1 < n && vis.count({prev_a, prev_b + 1}) == 0) {
      maxHeap.push({a[prev_a] + b[prev_b + 1], {prev_a, prev_b + 1}});
      vis.insert({prev_a, prev_b + 1});
    }
  }

  // Return the results vector.
  return result;
}
/*
TC: O(klogk + nlogn)
SC: O(k)
*/
```