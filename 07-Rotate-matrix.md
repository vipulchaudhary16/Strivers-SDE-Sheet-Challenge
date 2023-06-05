### [Rotate Matrix (CN)](https://www.codingninjas.com/codestudio/problems/rotate-matrix_8230774?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    if(n == 1 and m == 1) return;

    int top = 0, bottom = n-1, left = 0, right = m-1;

    while(top < bottom and left < right){
        int temp = mat[left][top]; // store the first element of the current layer

        for(int i = top; i < bottom; i++) mat[i][left] = mat[i+1][left]; // move the elements of the left column to the top
        for(int i = left; i < right; i++) mat[bottom][i] = mat[bottom][i+1]; // move the elements of the bottom row to the left
        for(int i = bottom; i > top; i--) mat[i][right] = mat[i-1][right]; // move the elements of the right column to the bottom
        for(int i = right; i > left+1; i--) mat[top][i] = mat[top][i-1]; // move the elements of the top row to the right

        mat[top][left+1] = temp; // move the first element of the current layer to the top row
        top++;
        bottom--;
        left++;
        right--;
    }

    /*
    TC: O(n*m)
    SC: O(1)
    */

}
```

### [Rotate Image (LeetCode) ](https://leetcode.com/problems/rotate-image/description/)


#### Not In Place Solution

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> temp(n, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                temp[j][n-i-1] = matrix[i][j]; // rotate the matrix by 90 degrees
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                matrix[i][j] = temp[i][j]; // copy the rotated matrix to the original matrix
        }

        /*
        TC: O(n^2)
        SC: O(n^2)
        */
        
    }
};
```

#### In Place Solution(Transpose + Reverse)

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> temp(n, vector<int>(n));

        // transpose the matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        // reverse each row
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        /*
        TC: O(n^2)
        SC: O(1)
        */
        
    }
};
```
