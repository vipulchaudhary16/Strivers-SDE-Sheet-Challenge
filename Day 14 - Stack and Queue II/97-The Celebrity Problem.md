### [The Celebrity Problem](https://www.codingninjas.com/studio/problems/the-celebrity-problem_8230781?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force Approach
```cpp
#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	int i;
 	for(i = 0; i < n; i++){
		bool canBe = true;
		for(int j = 0; j < n; j++){
			if(i != j){
				if(knows(i, j)){
					canBe = false;
					break;
				}
			}
		}
		if(canBe){
			for(int j = 0; j < n; j++){
				if(i != j){
					if(!knows(j, i)){
						return -1;
					}
				}
			}
			return i;
		}
	}
	return -1;
}
/*
TC: O(n^2)
SC: O(1)
*/
```