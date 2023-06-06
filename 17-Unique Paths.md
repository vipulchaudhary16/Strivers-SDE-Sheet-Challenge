### [Unique Paths](https://www.codingninjas.com/codestudio/problems/unique-paths_8230802?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### DP 

```cpp
#include <bits/stdc++.h> 

int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
	if(i >= m or j >= n) return 0;
	if(i == m-1 and j == n-1) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	int ans = 0;
	ans += solve(i+1, j, m, n, dp);
	ans += solve(i, j+1, m, n, dp);
	return dp[i][j] = ans;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return solve(0, 0, m, n, dp);
}
```