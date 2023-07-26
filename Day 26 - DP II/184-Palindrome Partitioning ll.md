### [Palindrome Partitioning ll](https://www.codingninjas.com/studio/problems/palindrome-partitioning-ll_8230732?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 

bool isPalindrome(int i, int j, string &s){
  while(i < j){
      if(s[i] != s[j]) return false;
      i++, j--;
  }
  return true;
}

int solve(int i, string &s, vector<int> &dp){
  if(i == s.size()) return 0; //base case

  if(dp[i] != -1)return dp[i]; //if already calculated

  int mini = 1e9; //initializing the minimum cuts to a very large value
  for(int ind = i; ind < s.size(); ind++){
      if(isPalindrome(i, ind, s)){ //if the current substring is a palindrome
          int cuts = 1 + solve(ind+1, s, dp); //we have to make one cut and then we have to find the minimum cuts for the remaining string
          mini = min(mini, cuts); //storing the minimum cuts
      }
  }

  return dp[i] = mini;
}
int palindromePartitioning(string str) {
  vector<int> dp(str.size(), -1);
  return solve(0, str, dp)-1;
}
/*
TC = O(n*n)
SC = O(n)
*/
```