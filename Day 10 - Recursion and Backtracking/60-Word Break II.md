### [Word Break II](https://www.codingninjas.com/codestudio/problems/word-break-ii_8230786?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

void solve(int ind, string state, string &s, map<string, int> &dic_freq, vector<string> &ans){
    if(ind == s.size()){ // base case, when we reach the end of the string
        ans.push_back(state); 
        return;
    }

    for(int i = ind; i < s.size(); i++){
        string curr = s.substr(ind, i - ind + 1); // current substring from ind to i
        if(dic_freq[curr] >= 1){
            int n = state.size(); // size of the current state
            state += (curr + " "); // add the current substring to the state
            solve(i+1, state, s, dic_freq, ans); // call the function for the next index
            state.erase(n); // remove the current substring from the state
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    map<string, int> dic_freq;
    for(auto str: dictionary){
        dic_freq[str]++; // store the frequency of each word in the dictionary
    }
    solve(0, "", s, dic_freq, ans);
    return ans;
}

/*
TC: O(N^2)
SC: O(N^2)
*/
```