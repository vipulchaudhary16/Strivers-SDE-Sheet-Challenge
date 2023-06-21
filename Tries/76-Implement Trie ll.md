### [Implement Trie ll](https://www.codingninjas.com/studio/problems/implement-trie-ll_8230840?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
class Node{
  public:
    char data;
    Node* children[26];
    int terminalCount = 0; // how many words end at this node
    int innerCount = 0; // how many words pass through this node

    Node(char data) {
        this->data = data;
        for(int i = 0; i < 26; i++) children[i] = NULL;
        this->terminalCount = 0;
        this->innerCount = 0;
    }
};

class Trie{

    public:
    Node * root;
    Trie(){
        root = new Node('v');
    }

    void insert(string &word){
        insertHelper(root, word);
    }

    void insertHelper(Node * root, string word){
        if(word.length() == 0){ // base case
            root -> innerCount++;
            root -> terminalCount++; // increment the terminal count because a word is ending at this node
            return;
        }

        int index = word[0] - 'a'; 

        if(root->children[index] == NULL){
            root->children[index] = new Node(word[0]);
        }

        root->innerCount++; // increment the inner count because a word is passing through this node

        insertHelper(root->children[index], word.substr(1));
    }

    int countWordsEqualTo(string &word){
        return searchHelper(root, word);
    }

    int searchHelper(Node * root, string word){
      if(word.length() == 0){
        return root->terminalCount; // base case  
      }

      int index = word[0] - 'a';

      if(root->children[index] == NULL){ // if the node is not present
        return 0;
      }

      return searchHelper(root->children[index], word.substr(1));
    }

    int countWordsStartingWith(string &word){
        return startsWithHelper(root, word);
    }

    int startsWithHelper(Node * root, string word){
      if(word.length() == 0) return root->innerCount; // base case

      int index = word[0] - 'a';

      if(root->children[index] == NULL) return 0; // if the node is not present

      return startsWithHelper(root->children[index], word.substr(1));
    }

    void erase(string &word){
        eraseHelper(root, word);
    }

    void eraseHelper(Node * root, string word){
        if(word.length() == 0){
            root->innerCount--; // decrement the inner count because a word is passing through this node
            root->terminalCount--; // decrement the terminal count because a word is ending at this node
            return;
        }

        int index = word[0] - 'a';

        if(root->children[index] == NULL){
            return;
        }
        root->innerCount--; // decrement the inner count because a word is passing through this node 

        eraseHelper(root->children[index],  word.substr(1));
    }
};
```