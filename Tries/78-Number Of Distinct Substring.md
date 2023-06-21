### [Number Of Distinct Substring](https://www.codingninjas.com/studio/problems/number-of-distinct-substring_8230842?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force

```cpp
#include <bits/stdc++.h> 
int distinctSubstring(string &word) {
  set<string> st;
  int n = word.size();

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= n - i; ++j) {
      st.insert(word.substr(i, j));
    }
  }

  return st.size();
}
/*
TC: O(n^3)
SC: O(n^2)
*/
```

#### Optimized

### [GFG Link](https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1)

```cpp
struct Node
{
    Node *children[26];

    void insert(char ch, Node *newNode)
    {
        children[ch - 'a'] = newNode;
    }

    Node *getKeyChild(char ch)
    {
        return children[ch - 'a'];
    }

    bool containsKeyChild(char ch)
    {
        return children[ch - 'a'] != NULL;
    }
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    Node *root = new Node();
    int count = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        Node *node = root;
        for(int j = i; j < s.size(); j++)
        {
            if(!node->containsKeyChild(s[j]))
            {
                node->insert(s[j], new Node());
                count++;
            }
            
            node = node->getKeyChild(s[j]);
        }
    }
    
    return count + 1;
}
```
