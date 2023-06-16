### [Median of two sorted arrays](https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_8230788?challengeSlug=striver-sde-challenge)

#### Brute Force Approach
```cpp
double median(vector<int>& a, vector<int>& b) {
	int n = a.size(), m = b.size();
	int i = n-1, j = m-1, k = m+n-1;
	a.resize(m+n);
	
  // merge two sorted arrays
	while(i >= 0 and j >= 0){
		if(a[i] >= b[j]){
			a[k--] = a[i--];
		} else {
			a[k--] = b[j--];
		}
	}
	while(j > 0) a[k--] = b[j--]; // if b is not empty

	int len = m+n;

	double ans;
	if(len % 2 == 0){ // if length is even then median is average of middle two elements
		ans = ((double) a[len/2] + (double) a[len/2 - 1])/((double) 2);
	} else { // if length is odd then median is middle element
		ans = ((double) a[len/2]);
	}
	return ans;
}
/*
TC: O(N+M)
SC: O(1)
*/
```

#### Optimal Approach
```cpp
double median(vector<int>& a, vector<int>& b) {
	int m = a.size(), n = b.size();
	if(m > n) return median(b, a); // to ensure m <= n always for binary search

	int low = 0, high = m, medianPos = (m+n+1)/2; // medianPos is the position of median in merged array

	while(low <= high){
		int cut1 = (low+high)/2; // cut1 is the position of cut in first array
		int cut2 = medianPos - cut1; // cut2 is the position of cut in second array

		int l1 = cut1 == 0 ? INT_MIN : a[cut1-1]; // l1 is the left element of cut in first array
		int l2 = cut2 == 0 ? INT_MIN : b[cut2-1]; // l2 is the left element of cut in second array
		int r1 = cut1 == m ? INT_MAX : a[cut1]; // r1 is the right element of cut in first array
		int r2 = cut2 == n ? INT_MAX : b[cut2]; // r2 is the right element of cut in second array

		if(l1 <= r2 and l2 <= r1){ // if both the arrays are sorted
			if((m+n)%2 != 0){ // if length of merged array is odd
				return max(l1, l2); // median is the maximum of left elements
			} else { // if length of merged array is even
				return (max(l1, l2) + min(r1, r2))/2.0; // median is the average of maximum of left elements and minimum of right elements
			}
		}
		else if(l1 > l2) high = cut1 - 1; // if l1 > l2 then we need to move cut1 to left
		else low = cut1 + 1; // if l1 < l2 then we need to move cut1 to right
	}

	return 0.0;
	
}
/*
TC: O(log(min(N, M)))
SC: O(1)
*/
```