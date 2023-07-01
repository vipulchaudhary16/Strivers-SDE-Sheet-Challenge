### [Roman Numeral To Integer](https://www.codingninjas.com/studio/problems/roman-numeral-to-integer_8230780?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
int romanToInt(string s) {
    unordered_map<char,int> mp{
        {'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}
    };
    int ans = 0;

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]])
            ans-=mp[s[i]];
        else
            ans+=mp[s[i]];
    }
    return ans;
}
```