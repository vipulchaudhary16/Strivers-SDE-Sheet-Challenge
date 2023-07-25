### [Maximum Product Subarray](https://www.codingninjas.com/studio/problems/maximum-product-subarray_8230828?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
/*
Algorithm:
1. Initialize ans = arr[0], prod = 1
2. Iterate over the array
  2.1 prod *= arr[i]
  2.2 ans = max(ans, prod)
  2.3 if(arr[i] == 0) prod = 1
3. Initialize prod = 1
4. Iterate over the array in reverse
  4.1 prod *= arr[i]
  4.2 ans = max(ans, prod)
  4.3 if(arr[i] == 0) prod = 1
5. return ans

Why reverse iteration?
Because if we have a negative number in the array, then we can get the maximum product by multiplying it with the minimum product of the subarray to its left.
*/
#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int ans = arr[0];
	int prod = 1;


	for(int i = 0; i < n; i++){
		prod *= arr[i];
		ans = max(ans, prod);
		if(arr[i] == 0) prod = 1;
	}

	prod = 1;
	for(int i = n-1; i >= 0; i--){
		prod *= arr[i];
		ans = max(ans, prod);
		if(arr[i] == 0) prod = 1;
	}

	return ans;
}

```