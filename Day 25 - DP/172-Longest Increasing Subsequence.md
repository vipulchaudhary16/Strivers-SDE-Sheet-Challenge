### [Longest Increasing Subsequence](https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_8230689?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<vector>

int solve(int curr_ind, int prev_ind, int nums[], int n, vector<vector<int>> &dp){
        if(curr_ind == n) return 0;

        if(dp[curr_ind][prev_ind+1] != -1) return dp[curr_ind][prev_ind+1];

        int notTake = solve(curr_ind + 1, prev_ind, nums,n, dp);

        int take = 0;
        if(prev_ind == -1 or nums[curr_ind] > nums[prev_ind])
            take = 1 + solve(curr_ind + 1, curr_ind, nums, n, dp);

        return dp[curr_ind][prev_ind+1] = max(take, notTake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(0, -1, arr, n, dp);
}
```