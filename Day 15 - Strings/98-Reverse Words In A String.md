### [Reverse Words In A String](https://www.codingninjas.com/studio/problems/reverse-words-in-a-string_8230698?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>

string reverseString(string &str){
	stack<string> stk;
	string res = ""	;
	int n = str.size();

	for(int i = 0; i < n;){
		string word = "";
		while(i < n && str[i] != ' ') word += str[i++];
		while(i < n && str[i] == ' ') i++;
		stk.push(word);
	}

	while(!stk.empty()){
		res += stk.top();
		if(stk.size() != 1) res += " ";
		stk.pop();
	}

	return res;
}
/*
TC: O(n)
SC: O(n)
*/
```