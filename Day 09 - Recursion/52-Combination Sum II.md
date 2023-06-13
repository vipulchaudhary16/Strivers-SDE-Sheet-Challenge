### [Combination Sum II](https://www.codingninjas.com/codestudio/problems/combination-sum-ii_8230820?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<set>
#include<algorithm>

void f(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>& ds) {
  if(target == 0){
    ans.push_back(ds); //push the current subset to ans vector of subsets 
    return;
  }

  for(int i = ind; i < arr.size(); i++){
    if(i > ind && arr[i] == arr[i - 1]) continue; //skip duplicates
    if(arr[i] > target) break; //if the current element is greater than target, break
	
    ds.push_back(arr[i]);  //take it
    f(i + 1, target - arr[i], arr, ans, ds); //recurse
    ds.pop_back(); //backtrack
  }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(), arr.end()); //sort the array to skip duplicates
	vector < vector < int >> ans;
	vector < int > ds;
	f(0, target, arr, ans, ds);
	return ans;
}
/*
TC: O(2^n)
SC: O(2^n)
*/
```