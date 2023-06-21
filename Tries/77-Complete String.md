### [Complete String](https://www.codingninjas.com/studio/problems/complete-string_8230849?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

class Node{
    public:
      char data;
      Node * children[26];
      bool isTerminal;

      Node(int data){
        this->data = data;
        for(int i = 0; i < 26; i++) this->children[i] = NULL;
        this->isTerminal = false;
      }
};

class Trie{
    public:
      Node * root;

    Trie(){
      root = new Node('x');
    }

    void insert(string word){
      Node * curr = root;
      for(auto ch:word){
        if(curr->children[ch-'a'] == NULL){
            curr->children[ch-'a'] = new Node(ch);
        }
        curr = curr->children[ch-'a'];
      }
      curr->isTerminal = true;
    }

    bool isAllPrefixExists(string word){
      Node * curr = root;
      for(auto ch:word){
        if(curr->children[ch-'a'] == NULL) return false;
        curr = curr->children[ch-'a'];
        if(curr->isTerminal == false) return false;
      }
      return true;
    }
};

string completeString(int n, vector<string> &a){
  Trie trie;
  for (string word : a) {
    trie.insert(word);
  }

  string res = "";
  for (string word : a) {
    if (trie.isAllPrefixExists(word)) {
      if (word.length() == res.length()) {
        res = min(res, word);
      } else if (word.length() > res.length()) {
        res = word;
      }
    }
  }
  return res.empty() ? "None" : res;
}
```