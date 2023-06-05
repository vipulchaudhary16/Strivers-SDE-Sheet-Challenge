### [Search In A 2D Matrix](https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_8230773?challengeSlug=striver-sde-challenge)

#### Brute Force Approach:
```cpp
#include <bits/stdc++.h>
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == target) return true;
        }
    }
    return false;

    /*
    TC: O(n*m)
    SC: O(1)
    */
}
```

#### Binary Search Approach:
```cpp
bool binary_search(vector<int> &arr, int value) {
  int low = 0;
  int high = arr.size() - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == value) {
      return true;
    } else if (arr[mid] < value) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return false;
  /*
  TC: O(logn)
  SC: O(1)
  */
}


bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();

    for(int i = 0; i < m; i++){
        if(binary_search(mat[i], target)) return true;
    }

    return false;
    /*
    TC: O(mlogn)
    SC: O(1)
    */
}
```

#### Optimal Approach:
```cpp
bool searchMatrix(vector<vector<int>>& mat, int target) {
  int n = mat.size(), m = mat[0].size();

  int low = 0, high = (n*m)-1;

  while(low <= high){
      int mid = (low + high)/2;
      int i = mid/m, j = mid%m; // converting 1D index to 2D index

      // merge sort type of approach
      if(mat[i][j] == target) return true;
      else if(mat[i][j] > target) high = mid-1;
      else low = mid+1;
  }

  return false;
  /*
  TC: O(logn)
  SC: O(1)
  */
}
```