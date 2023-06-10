### [Remove Duplicates from Sorted Array](https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_8230811?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
int removeDuplicates(vector<int> &arr, int n) {
	int i = 0, j = 1;
	while(j < n){
		if(arr[j] != arr[i]){
			i++;
			arr[i] = arr[j];
		}
		j++;
	}
	return i+1;
}
/*
TC: O(N)
SC: O(1)
*/
```