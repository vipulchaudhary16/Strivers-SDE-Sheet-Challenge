### [Longest Subarray Zero Sum](https://www.codingninjas.com/codestudio/problems/longest-subarray-zero-sum_8230747?challengeSlug=striver-sde-challenge)

#### Brute Force Approach
```cpp
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  int  maxi = 0;
	for(int i = 0; i < arr.size(); i++){
		int sum = 0;
		for(int j = i; j < arr.size(); j++){
			sum += arr[j];
			if(sum == 0){
				maxi = max(maxi, j-i+1);
			}
		}
	}
	return maxi;
	/*
	Time Complexity: O(n^2)
	Space Complexity: O(1)
	*/
}
```

#### Optimal Approach
```cpp
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
	unordered_map<int, int> presum_ind; // presum, index
	int maxi = 0; // max length of subarray with zero sum
	int preSum = 0; // prefix sum

	for(int i = 0; i < arr.size(); i++){
		int curr = arr[i];
		preSum += curr;
		if(preSum == 0){ // if prefix sum is zero, then the subarray from index 0 to i has zero sum
			maxi = i+1;
		} else if(presum_ind[preSum]){ // if prefix sum is already present in the map, then the subarray from index i to presum_ind[preSum] has zero sum
			maxi = max(maxi, i - presum_ind[preSum]);
		} else {
			presum_ind[preSum] = i; // store the index of the prefix sum
		}
	}

	return maxi;

	/*
	Time Complexity: O(n)
	Space Complexity: O(n)
	*/

}
```