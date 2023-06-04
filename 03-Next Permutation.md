### [Next Permutation](https://www.codingninjas.com/codestudio/problems/next-permutation_8230741?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int k; // index of first element from right to left such that permutation[k] < permutation[k+1], peak element
    for(k = n - 2; k >=0; k--){
        if(permutation[k+1] > permutation[k]) break;
    }
    if(k < 0){ // permutation is in descending order
        reverse(permutation.begin(), permutation.end());
    } else {
        int l; // index of first element from right to left such that permutation[l] > permutation[k]
        for(l = n-1; l >= 0; l--){
            if(permutation[l] > permutation[k]) break;
        }
        swap(permutation[k], permutation[l]); 
        reverse(permutation.begin()+k+1, permutation.end()); 
    }

    return permutation;
    /*
    TC = O(n)
    SC = O(1)
    */
}
```
