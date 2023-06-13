### [Palindrome Partitioning](https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_8230726?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]) return false;
    }
    return true;
}

void f(int i, string s, vector<string> &container, vector<vector<string>> &ans){
    if(i == s.size()){
        ans.push_back(container);
        return;
    }

    for(int j = i; j < s.size(); j++){
        if(isPalindrome(s, i, j)){ //if s[i...j] is a palindrome
            container.push_back(s.substr(i, j-i+1)); //push it in the container
            f(j+1, s, container, ans); //recurse for the remaining string
            container.pop_back(); //backtrack
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> container;
    f(0, s, container, ans );
    return ans;
}
/*
TC: O(n*2^n)
SC: O(n)
*/
```