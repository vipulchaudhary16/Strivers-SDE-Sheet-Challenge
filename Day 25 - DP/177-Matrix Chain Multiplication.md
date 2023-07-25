### [Matrix Chain Multiplication](https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_8230769?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
int dp[101][101];

int f(int i, int j, vector<int> arr){
    if(i == j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i-1] * arr[j] * arr[k] + f(i, k, arr) + f(k+1, j, arr);
        mini = min(steps, mini);
    }
    return dp[i][j] = mini;
}
   
int matrixMultiplication(vector<int> &arr, int N)
{
    memset(dp, -1, sizeof dp);
    return f(1, N-1, arr);
}
```