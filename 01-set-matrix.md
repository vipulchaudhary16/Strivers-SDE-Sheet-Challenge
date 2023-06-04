### [Set Matrix Zeros](https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_8230862?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Extra space approach

```cpp
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int r = matrix.size(), c = matrix[0].size();
	vector<int> rows(r,-1), cols(c, -1); // -1 means not zero, 0 means zero in the row/col

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(matrix[i][j] == 0) { // if zero, mark the row and col
				rows[i] = 0;
				cols[j] = 0;
			}
		}
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(rows[i] == 0 or cols[j] == 0) matrix[i][j] = 0; // if row or col is marked, make the element zero
		}
	}
	/*
	TC = O(r*c) + O(r*c)
	SC = O(r) + O(c)
	*/
}
```

#### Optimized approach

```cpp
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int r = matrix.size(), c = matrix[0].size();
	bool col0 = false; // to check if first col has zero because we are using first col as a marker

	for(int i = 0; i < r; i++){
		if(matrix[i][0] == 0) col0 = true; // if first col has zero, mark it as true
		for(int j = 1; j < c; j++){
			if(matrix[i][j] == 0){ // if zero, mark the first element of the row and col
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

  // start from bottom right because we are using first row and col as marker
	for(int i = r-1; i >= 0; i--){
		for(int j = c-1; j >= 1; j--){
			if(matrix[i][0] == 0 or matrix[0][j] == 0) matrix[i][j] = 0; // if first element of row or col is marked, make the element zero
		}
		if(col0) matrix[i][0] = 0; // if first col has zero, make curr element of first col zero
	}
	/*
	TC = O(r*c) + O(r*c)
	SC = O(1)
	*/
}
```