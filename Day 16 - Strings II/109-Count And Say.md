### [Count And Say](https://www.codingninjas.com/studio/problems/count-and-say_8230807?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	if(n == 1) return "1";
	if(n == 2) return "11";

	string ans = "11";

	for(int i = 3; i <= n; i++){
		string curr = "";
		ans += "$"; // delimiter so that we can count the last character
		
		int count = 1; // count of the current character in the string ans 
		for(int j = 1; j < ans.size(); j++){
			if(ans[j] == ans[j-1]){ // if the current character is same as the previous character
				count++;
			} else {
				curr += to_string(count); // append the count of the previous character
				curr += ans[j-1]; // append the previous character
				count = 1; // reset the count
			}
		}
		ans = curr; // update the string ans
	}

	return ans;
}
```