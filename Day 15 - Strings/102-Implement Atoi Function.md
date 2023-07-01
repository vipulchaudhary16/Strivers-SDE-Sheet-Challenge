### [Implement Atoi Function](https://www.codingninjas.com/studio/problems/implement-atoi-function_8230776?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
int atoi(string str) {
    bool isNeg = false;
    int n = str.size();
    string res = "";

    for(auto ch: str){
        if(ch == '-') isNeg = true;
        else if(ch < 65) res += ch;
    }

    return isNeg ? -1 * stoi(res) : stoi(res);
}
```