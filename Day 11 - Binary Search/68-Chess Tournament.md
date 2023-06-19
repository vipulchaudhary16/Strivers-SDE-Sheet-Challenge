### [Chess Tournament](https://www.codingninjas.com/codestudio/problems/chess-tournament_8230779?challengeSlug=striver-sde-challenge)

#### Brute Force

```cpp
#include <bits/stdc++.h> 
bool isOk(vector<int> &pos, int focus, int players){
	int k = pos[0]; // first player
	players--; // first player is already allocated
	for(int i = 1; i < pos.size(); i++){
		if(pos[i] - k >= focus){ // if current player can be allocated
			players--; // allocate current player
			if(players == 0) return 1; // if all players are allocated
			k = pos[i]; // update the current player
		}
	}
	return 0; // if all players are not allocated
}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
	int maxi = positions[n-1] - positions[0]; // maximum possible answer

	int ans = INT_MIN;
	for(int i = 1; i <= maxi; i++){
		if(isOk(positions, i, c)){ // if current answer is possible
			ans = max(ans, i); // update the answer
		}
	}

	return ans;
}
/*
TC = O(n^2)
SC = O(1)
*/
```

#### Binary Search

```cpp
#include <bits/stdc++.h> 

bool isOk(vector<int> &pos, int focus, int players){
	int k = pos[0]; // first player
	players--; // first player is already allocated
	for(int i = 1; i < pos.size(); i++){
		if(pos[i] - k >= focus){ // if current player can be allocated
			players--; // allocate current player
			if(players == 0) return 1; // if all players are allocated
			k = pos[i]; // update the current player
		}
	}
	return 0; // if all players are not allocated
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(), positions.end());
	int low = 1; // minimum possible answer
	int high = positions[n-1] - positions[0]; // maximum possible answer

	int ans = -1;
	while(low <= high){
		int mid = (low+high)/2;
		if(isOk(positions, mid, c)){
			low = mid+1;
			ans = mid;
		} else {
			high = mid-1;
		}
	}

	return ans;
}
/*
TC = O(nlogn)
SC = O(1)
*/
```