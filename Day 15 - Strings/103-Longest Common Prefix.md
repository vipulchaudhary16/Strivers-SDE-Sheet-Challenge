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


