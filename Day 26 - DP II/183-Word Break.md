### [Word Break](https://www.codingninjas.com/studio/problems/word-break_8230808?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h>

bool solve(int ind, vector<string> &arr, int n, string &target, vector<int> &dp) {
  if (ind == n)
    return true; // we have found a way to make the target string

  if (dp[ind] != -1)
    return dp[ind];

  for (auto word : arr)
    // if the current word is a prefix of the target string and we can make the remaining string
    if (target.substr(ind, word.size()) == word and 
        solve(ind + word.size(), arr, n, target, dp))
      return dp[ind] = true;

  return dp[ind] = false;
}

bool wordBreak(vector<string> &arr, int n, string &target) {
  vector<int> dp(target.size() + 1, -1);
  return solve(0, arr, target.size(), target, dp);
}
/*
TC = O(n*target.size())
SC = O(target.size())
*/
```