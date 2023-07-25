### [Longest Common Subsequence](https://www.codingninjas.com/studio/problems/longest-common-subsequence_8230681?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<vector>

int f(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){
	if(ind1<0 || ind2<0)
		return 0;

	if(dp[ind1][ind2]!=-1)
		return dp[ind1][ind2];

	if(s1[ind1] == s2[ind2])
		return dp[ind1][ind2] = 1 + f(s1,s2,ind1-1,ind2-1,dp);

	else 
		return dp[ind1][ind2] = 0 + max(f(s1,s2,ind1,ind2-1,dp),f(s1,s2,ind1-1,ind2,dp));
}

int lcs(string s, string t)
{
	int n=s.size();
	int m=t.size();

	vector<vector<int>> dp(n,vector<int>(m,-1));
	return f(s,t,n-1,m-1,dp);
}
```