### [Check Permutation](https://www.codingninjas.com/studio/problems/check-permutation_8230834?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    vector<int> str1_freq(26, 0), str2_freq(26, 0);

    for(auto c: str1){
        str1_freq[c - 'a'] = 1;
    }

    for(auto c: str2){
        str2_freq[c - 'a'] = 1;
    }

    for(int i = 0; i < 26; i++){
        if(str1_freq[i] != 1 and str2_freq[i] == 1) return false;
        if(str1_freq[i] == 1 and str2_freq[i] != 1) return false;
    }

    return true;
}
```