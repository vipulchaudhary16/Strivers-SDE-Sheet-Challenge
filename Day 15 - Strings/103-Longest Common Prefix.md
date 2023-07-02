### [Longest Common Prefix](https://www.codingninjas.com/studio/problems/longest-common-prefix_8230847?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
string longestCommonPrefix(vector<string> &arr, int n)
{
    int minLen = 10005;
    for(auto str: arr) minLen = min(minLen, (int)str.size());

    string res = "";

    for(int i = 0; i < minLen; i++){
        char ch = arr[0][i];
        for(int j = 0; j < arr.size(); j++){
            if(arr[j][i] != ch) return res;
        }
        res += ch;
    }

    return res;
}
```

#### Using trie

```cpp
class TrieNode{
    public:
        char data;
        TrieNode * children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char data){
            this -> data = data;
            this -> isTerminal = false;
            this -> childCount = 0;
            for(int i = 0; i < 26; i++){
                this -> children[i] = NULL;
            }
        }
};

class Trie{
public:
    TrieNode * root;
    
    Trie(){
        this -> root = new TrieNode('\0');
    }
    void insertWord(string word){
        TrieNode * curr = root;
        for(auto ch:word){
            if(curr->children[ch-'a'] == NULL){
                curr->childCount++;
                curr->children[ch-'a'] = new TrieNode(ch);
            }
            curr = curr->children[ch-'a'];
        }
        curr->isTerminal = true;
    }
    
    void lcp(string &str, string &ans){
        TrieNode * temp = root;
        for(auto c : str){
            if(temp -> childCount == 1){
                ans.push_back(c);
                int ind = c - 'a';
                temp = temp -> children[ind];
            } else break;
            
            if(temp -> isTerminal) break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie * t = new Trie();
    for(auto word : arr) {
        if(word.empty())
            return "";
        t->insertWord(word);
    }
    
    string ans = "";
    t -> lcp(arr[0], ans);
    
    return ans;
}
```


