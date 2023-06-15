### [Single Element in a Sorted Array](https://www.codingninjas.com/codestudio/problems/single-element-in-a-sorted-array_8230826?challengeSlug=striver-sde-challenge)

#### Brute Force Approach
```cpp
#include<bits/stdc++.h>

int singleNonDuplicate(vector<int>& arr)
{
	unordered_map<int, int> mp;
	for(auto a: arr) mp[a]++;
	for(auto it: mp) if(it.second == 1) return it.first;
	return -1;
}
/*
TC: O(N)
SC: O(N)
*/
```
#### Observations
- The array is sorted
- The array has all elements repeated twice except one element
- If we are in right half of the array, then the index of the first element should be odd
- If we are in left half of the array, then the index of the first element should be even
- Shrinking the search space by half


#### Optimized Approach

```cpp
#include<bits/stdc++.h>

int singleNonDuplicate(vector<int>& arr)
{
	int low = 0;
	int high = arr.size()-2;

	while(low <= high){
		int mid = (low+high)/2;
		if(mid % 2 == 0){
			if(arr[mid] != arr[mid+1]){
				//right half
				high = mid-1;
			} else {
        //left half
				low = mid+1;
			}
		} else {
			if(arr[mid] == arr[mid+1]){
				//right half
				high = mid-1;
			} else {
        //left half
				low = mid+1;
			}
		}
	}

	return arr[low];
}
/*
TC: O(logN)
SC: O(1)
*/
```