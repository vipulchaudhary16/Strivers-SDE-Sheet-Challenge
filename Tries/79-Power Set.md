### [Power Set](https://www.codingninjas.com/studio/problems/power-set_8230797?challengeSlug=striver-sde-challenge)

```cpp
#include <bits/stdc++.h> 

void f(int i, vector<int> arr, vector<int> subst, vector<vector<int>> &result){
    if(i == arr.size()){
        result.push_back(subst);// base case, came to end of the array
        return;
    }

    subst.push_back(arr[i]); //take
    f(i+1, arr, subst, result);
    subst.pop_back(); // backtrack
    f(i+1, arr, subst, result); //don't take
}

vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> result;
    vector<int> subst;
    f(0, v, subst, result);
    return result;
}
/*
TC: O(2^n)
SC: O(2^n)
*/
```