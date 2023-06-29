### [Min Stack](https://www.codingninjas.com/studio/problems/min-stack_8230861?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
class minStack
{
	public:
		
		stack<pair<int, int>> st; // {element, min_element}
		minStack() {}
		
		void push(int num)
		{
			//we are trying to keep min element on top before every push
			if(!st.empty() && st.top().second < num)
				st.push({num, st.top().second});
			else st.push({num, num});
		}
		
		int pop()
		{
			if(st.empty()) return -1;
			auto mini = st.top();
			st.pop();
			return mini.first;
		}
		
		int top()
		{
			if(st.empty()) return -1;
			return st.top().first;
		}
		
		int getMin()
		{
			if(st.empty()) return -1;
			return st.top().second;
		}
};
```