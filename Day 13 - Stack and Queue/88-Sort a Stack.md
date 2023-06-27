### [Sort a Stack](https://www.codingninjas.com/studio/problems/sort-a-stack_8230787?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force
```cpp
#include <bits/stdc++.h> 
void sortStack(stack<int> &st)
{
	vector<int> arr;
	while(!st.empty()){
		arr.push_back(st.top());
		st.pop();
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i < arr.size(); i++){
		st.push(arr[i]);
	}
}
```

#### Optimized
```cpp
#include <bits/stdc++.h> 
void sortedInsertion(stack<int> &st, int num){
	if(st.empty() || st.top() < num){
		st.push(num);
		return;
	}

	int numm = st.top();
	st.pop();

	sortedInsertion(st, num);
	st.push(numm);
}

void sortStack(stack<int> &st)
{
  // empty the stack and then insert the elements in sorted order
	if(st.empty()) return;
	int top = st.top();
	st.pop();
	sortStack(st);
  
	sortedInsertion(st, top);
}
/*
TC: O(n^2)
SC: O(n)
*/
```

