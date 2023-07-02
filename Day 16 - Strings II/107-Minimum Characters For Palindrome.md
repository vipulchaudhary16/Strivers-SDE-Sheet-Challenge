### [Minimum Characters For Palindrome](https://www.codingninjas.com/studio/problems/minimum-characters-for-palindrome_8230737?challengeSlug=striver-sde-challenge&leftPanelTab=0)

### Brute Force
```cpp

int minCharsforPalindrome(string str) {
	int i = 0, j = str.size()-1;
	int trim = j, ans = 0; //trim is the last index of the string after trimming

	while(i < j){
		if(str[i] == str[j]){
			i++;
			j--;
		} else {
			ans++; //added one char for last char
			trim--; //trim the last char from the string and check again for palindrome
			i = 0; //reset i to 0
			j = trim; //reset j to trim
		}
	}
	return ans;
}
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
```

### KMP Algorithm
```cpp
#include <iostream>
#include <vector>
using namespace std;

int minCharsforPalindrome(string str) {
    int n = str.length();

    // Create a temporary string with the original string 
	//concatenated with a special character and its reverse
    string temp = str + "#" + string(str.rbegin(), str.rend());

    // Calculate the longest prefix suffix that is also a prefix for the temporary string
    vector<int> lps(temp.length(), 0);
    int len = 0;
    int i = 1;

    while (i < temp.length()) {
        if (temp[i] == temp[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // The minimum characters required to make the string a palindrome is 
	//the difference between the original string length and 
	//the length of the longest prefix suffix
    return n - lps[temp.length() - 1];
}
```