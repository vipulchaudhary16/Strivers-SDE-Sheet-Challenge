### [Print Permutations - String](https://www.codingninjas.com/codestudio/problems/day-13-print-permutations-string_8230703?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 
void f(int ind, string &s, vector<string> &result){
    if(ind == s.size()){
        result.push_back(s); // found a permutation
        return;
    }
    for(int i = ind; i < s.size(); i++){
        swap(s[i], s[ind]); // swap the current element with the first element
        f(ind+1, s, result); // find the permutation of the remaining string
        swap(s[i], s[ind]); // backtrack
    }
}
vector<string> findPermutations(string &s) {
    vector<string> result;
    f(0, s, result);
    return result;
}
/*
TC = O(n*n!)
SC = O(n*n!) // for storing the result
```