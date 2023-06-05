### [Find Duplicate in Array](https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_8230816?challengeSlug=striver-sde-challenge&leftPanelTab=0)

### Brute Force Solution

```cpp
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	sort(arr.begin(), arr.end());

	for(int i = 0; i < n-1; i++){
		if(arr[i] == arr[i+1]) return arr[i];
	}

	return -1;
  /*
  TC: O(nlogn + n)
  SC: O(1)
  */
}
```

### Extra Space Solution

```cpp
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
  vector<int> temp(n, 0);

  for(int i = 0; i < n; i++){
    if(temp[arr[i]] == 1) return arr[i];
    temp[arr[i]] = 1;
  }

  return -1;
  /*
  TC: O(n)
  SC: O(n)
  */
}
```

### Optimal Solution

```cpp
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
  // Floyd's Tortoise and Hare (Cycle Detection) Algorithm
  int slow = arr[0], fast = arr[0];

  // find the intersection point of the two pointers
  // here we are using do-while loop because we want to run the loop atleast once
  do{
    slow = arr[slow];
    fast = arr[arr[fast]];
  }while(slow != fast);

  fast = arr[0];

  // find the starting point of the cycle
  while(slow != fast){
    slow = arr[slow];
    fast = arr[fast];
  }

  // return the duplicate element, which is the starting point of the cycle
  return slow;

  /*
  TC: O(n)
  SC: O(1)
  */
}
```