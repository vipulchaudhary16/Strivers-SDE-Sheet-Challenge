### [Kth Element of Two Sorted Arrays](https://www.codingninjas.com/codestudio/problems/kth-element-of-two-sorted-arrays_8230824?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force Approach:
```cpp
int kthElement(vector<int>& arr1, vector<int>& arr2, int n, int m, int k) {
    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            count++;
            if (count == k) {
                return arr1[i];
            }
            i++;
        }
        else {
            count++;
            if (count == k) {
                return arr2[j];
            }
            j++;
        }
    }
    while (i < n) {
        count++;
        if (count == k) {
            return arr1[i];
        }
        i++;
    }
    while (j < m) {
        count++;
        if (count == k) {
            return arr2[j];
        }
        j++;
    }
    return -1;
}
```

```cpp
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    vector<int> finalArray;
    int i = 0, j = 0;
    while(i < n and j < m){
        if(row1[i] < row2[j]){
            finalArray.push_back(row1[i++]);
        } else {
            finalArray.push_back(row2[j++]);
        }
    }
    while(i < n) finalArray.push_back(row1[i++]);
    while(j < m) finalArray.push_back(row2[j++]);

    return finalArray[k-1];
}
```

#### Optimized Approach:
```cpp
#include <bits/stdc++.h>
using namespace std;

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) {
  if (n > m)
    return ninjaAndLadoos(row2, row1, m, n, k);

  int low = max(0, k - m), high = min(n, k); // cannot take all elements 
  while (low <= high) {
    int cut1 = (low + high) >> 1;
    int cut2 = k - cut1;

    int l1 = cut1 == 0 ? INT_MIN : row1[cut1 - 1];
    int l2 = cut2 == 0 ? INT_MIN : row2[cut2 - 1];
    int r1 = cut1 == n ? INT_MAX : row1[cut1];
    int r2 = cut2 == m ? INT_MAX : row2[cut2];

    if (l1 <= r2 and l2 <= r1)
      return max(l1, l2);
    else if (l1 > r2)
      high = cut1 - 1;
    else
      low = cut1 + 1;
  }

  return 1;
}
/*
TC: O(log(min(n, m)))
SC: O(1)
*/
```