### [Pascal's Triangle](https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_8230805?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans(n);

  for(int i = 0; i < n; i++){
    ans[i].resize(i+1); // because each row has i+1 elements 
    ans[i][0] = ans[i][i] = 1; // first and last element is 1

    for(int j = 1; j < i; j++) 
      ans[i][j] = ans[i-1][j-1] + ans[i-1][j]; // middle elements are sum of two elements from previous row
  }

  return ans;
}

/*
TC = O(n^2) // n is the number of rows
SC = O(n^2) // using 2D vector to store the triangle
*/
```