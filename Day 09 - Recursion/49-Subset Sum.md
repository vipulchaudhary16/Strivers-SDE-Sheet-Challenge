### [Subset Sum](https://www.codingninjas.com/codestudio/problems/subset-sum_8230859?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

void f(int i, vector<int> &num, vector<int> &ans, int sum){
    if(i >= num.size()) return;
    //don't take it
    f(i+1, num, ans, sum);
    //take it
    sum += num[i];
    ans.push_back(sum);
    f(i+1, num, ans, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    ans.push_back(0); //empty subset

    f(0, num, ans, 0);

    sort(ans.begin(), ans.end()); //sort the ans vector
    return ans;
    /*
    TC: O(2^n)
    SC: O(2^n)
    */
}
```