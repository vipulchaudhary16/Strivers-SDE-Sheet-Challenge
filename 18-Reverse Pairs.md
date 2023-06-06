### [Reverse Pairs](https://www.codingninjas.com/codestudio/problems/reverse-pairs_8230825?challengeSlug=striver-sde-challenge)

#### Brute Force Approach
```cpp
#include <bits/stdc++.h> 

int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(arr[i] > arr[j]*2) ans++;
		}
	}
	return ans;
}
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
```

#### Merge Sort Approach
```cpp
#include <bits/stdc++.h> 

int merge(vector < int > & arr, int low, int mid, int high) {
	int curr_total = 0;
	int j = mid+1;
	int i = low;
	while(i <= mid){
    // This is the main part of the code
    // If the element at i is greater than 2*element at j then count the number of elements from j to mid
		while(j <= high and arr[i] > ((long long) 2 * arr[j])) j++;
    // Add the count to the total count
		curr_total += (j - mid - 1);
		i++;
	}

  // Merge the two sorted arrays
	vector < int > t;
	int left = low, right = mid + 1;

	while (left <= mid && right <= high) {
		if (arr[left] <= arr[right]) {
			t.push_back(arr[left++]);
		} else {
			t.push_back(arr[right++]);
		}
	}

	while (left <= mid) {
		t.push_back(arr[left++]);
	}
	while (right <= high) {
		t.push_back(arr[right++]);
	}

  // Copy the sorted array to the original array
	for (int i = low; i <= high; i++) {
		arr[i] = t[i - low];
	}
	return curr_total;

}
    
int mergeSort(vector < int > & arr, int low, int high) {
	if (low >= high) return 0;
	int mid = (low + high) / 2;
	int ans = mergeSort(arr, low, mid);
	ans += mergeSort(arr, mid + 1, high);
	ans += merge(arr, low, mid, high);
	return ans;
}

int reversePairs(vector<int> &arr, int n){
	return mergeSort(arr, 0, n-1);
  /*
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
  */
}
/*