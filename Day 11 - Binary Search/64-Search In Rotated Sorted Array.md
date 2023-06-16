### [Search In Rotated Sorted Array](https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_8230687?challengeSlug=striver-sde-challenge)

#### Brute Force Approach:
```cpp
int search(int* arr, int n, int key) {
    int ind = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            ind = i;
            break;
        }
    }
    return ind;
}
/*
TC: O(n)
SC: O(1)
*/
```

#### Optimal Approach:
```cpp
int search(int* arr, int n, int key) {
  int low = 0, high = n-1;

  while(low <= high){
    int mid = (low+high)/2;
    if(arr[mid] == key) return mid;
    //is left half sorted?
    else if(arr[low] <= arr[mid]){
      // is key present in left half?
      if(key >= arr[low] and key <= arr[mid]){
        high = mid-1;
      } else {
        low = mid+1;
      }
    } else { //is right half sorted?
      // is key present in right half?
      if(key >= arr[mid] and key <= arr[high]){
        low = mid+1;
      } else {
        high = mid-1;
      }
    }
  }

  return -1;
}
```
