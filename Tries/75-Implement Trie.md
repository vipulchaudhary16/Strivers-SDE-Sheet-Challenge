### [Implement Trie](https://www.codingninjas.com/studio/problems/implement-trie_8230696?challengeSlug=striver-sde-challenge&leftPanelTab=0)


```cpp
class Node{
  public:
    char data;
    Node* children[26];
    bool isTerminal; // is end of word

    Node(char data) {
      this->data = data;
      for(int i = 0; i < 26; i++) children[i] = NULL;
      isTerminal = false; 
    }
};

class Trie {

public:
    Node * root;

    Trie() {
      root = new Node('v');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
      insertHelper(root, word);
    }

    void insertHelper(Node * root, string word){
      if(word.length() == 0){ // base case
        root->isTerminal = true;
        return;
      }

      int index = word[0] - 'a'; 

      if(root->children[index] == NULL){
        // create a new node and attach it to the root
        root->children[index] = new Node(word[0]);
      } 

      insertHelper(root->children[index], word.substr(1));
      /*
      TC: O(word.length())
      SC: O(1)
      */
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      return searchHelper(root, word);
    }

    bool searchHelper(Node * root, string word){
      if(word.length() == 0){
        return root->isTerminal; // base case 
      }

      int index = word[0] - 'a';

      if(root->children[index] == NULL){ // if the node is not present
        return false;
      }

      return searchHelper(root->children[index], word.substr(1));
      /*
      TC: O(word.length())
      SC: O(1)
      */
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      return startsWithHelper(root, prefix);
    }

    bool startsWithHelper(Node * root, string word){
      if(word.length() == 0) return true; // base case

      int index = word[0] - 'a';

      if(root->children[index] == NULL) return false; // if the node is not present

      return startsWithHelper(root->children[index], word.substr(1));
      /*
      TC: O(word.length())
      SC: O(1)
      */
    }

};
```