### [Edit Distance](https://www.codingninjas.com/studio/problems/edit-distance_8230685?challengeSlug=striver-sde-challenge)

```cpp
#include<bits/stdc++.h>

int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s1[i] == s2[j]) return dp[i][j] = solve(i-1, j-1, s1, s2, dp);
    else {
        int insert = solve(i, j-1, s1, s2, dp); //s1 ke pichhe ek char insert kar denge so i (s1 ka pointer) to waha hi rahega
        int _delete = solve(i-1, j, s1, s2, dp); //s1 ka char delete karenge to fir j (s2 ka pointer to waha hi rahega kyu ki match nhi mila iisi liye to remove kiya na)
        int replace = solve(i-1, j-1, s1, s2, dp); //jo replace kar diya to jis char ki need thi ussi se replace karenge na, to dono pointer change honge
        
        return dp[i][j] = 1 + min({insert, _delete, replace}); //ek operation karenge tino me se aur aage badhenge
    }
}

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, str1, str2, dp);
}
```