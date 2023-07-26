### [Cut Logs](https://www.codingninjas.com/studio/problems/cut-logs_8230782?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>

int f(int n,int k,vector<vector<int>>&dp)
{
    if (n <= 0 || k <= 0) return 0; // if either n or k is 0 then we can not make any cut
    if (k == 1) return n; // if we have only one cut then we can make n cuts of length 1
    if (n == 1) return 1; // if we have only one log then we can make only one cut
    if (dp[n][k] != -1) return dp[n][k];
    
    int ans = INT_MAX; // we have to minimize the number of cuts

    int low = 1;
    int high = n;
    while(low<=high)
    {
        int mid = low+(high-low)/2; // we are trying to find the best cut 
        int broken = f(mid-1,k-1,dp); // if we make a cut at mid then we have to make k-1 cuts in the remaining log
        int notBroken = f(n-mid,k,dp); // if we do not make a cut at mid then we have to make k cuts in the remaining log
        int result = max(notBroken,broken);

        ans = min(result+1,ans);

        if (broken<notBroken) // if broken is less than notBroken then we have to increase the length of the cut
            low=mid+1;
        else
            high=mid-1;
        
    }
    return dp[n][k]=ans;
}

int cutLogs(int k, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return f(n,k,dp);
}
/*
TC = O(n*k*log(n))
SC = O(n*k)
*/
```