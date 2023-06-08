### [Longest Substring Without Repeating Characters](https://www.codingninjas.com/codestudio/problems/longest-substring-without-repeating-characters_8230684?challengeSlug=striver-sde-challenge)

#### Brute Force Approach
```cpp
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.size();
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        set<char> st; // to store the characters of the substring
        for(int j = i; j < n; j++){
            if(st.count(input[j])){ // if the character is already present in the set, then break
                ans = max(ans, (j-i));
                break;
            }
            st.insert(input[j]);
        }
    }
    return ans == INT_MIN ? n : ans; // if all the characters are unique, then return n
    /*
    Time Complexity: O(n^2)
    Space Complexity: O(n)
    */
}
```

#### Optimal

```cpp
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
  int n = input.size();
  int ans = INT_MIN;
  int i = 0, j = 0;
  set<char> st;

  for(; j < n; j++){
    if(st.count(input[j])){
      // if the character is already present in the set, then remove the characters from the set till the character is not present in the set to make the substring unique
      while(i < j and st.count(input[j])){
        st.erase(input[i]);
        i++;
      }
    }
    ans = max(ans, (j-i+1));
    st.insert(input[j]);
  }
  return ans;
  /*
  Time Complexity: O(n)
  Space Complexity: O(n)
  */
}
```