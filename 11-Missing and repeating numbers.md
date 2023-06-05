### [Missing and repeating numbers](https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_8230733?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force Approach:
```cpp
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	vector<int> freq(n+1, -1);

	int a , b; // a = repeating, b = missing
	for(int ele: arr){
		if(freq[ele] == -1) freq[ele] = 0;
		else{
			a = ele;
		}
	}

	for(int i = 1; i <=n; i++){
		if(freq[i] == -1){
			b = i;
			break;
		}
	}

	return {b, a};
	/*
	TC: O(n)
	SC: O(n)
	*/
	
}
```

#### Optimal Approach:

```cpp
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n) {  
	pair<int,int> ans;  long long int len = n;
	// S = sum of n natural numbers
	// P = sum of squares of n natural numbers
	long long int S = (len * (len+1) ) /2;    
	long long int P = (len * (len +1) *(2*len +1) )/6;    
	long long int missingNumber=0, repeating=0;         
	
	for(int i=0;i<len; i++){       
		S -= (long long int)arr[i];       
		P -= (long long int)arr[i]*(long long int)arr[i];    
	}       
	missingNumber = (S + P/S)/2;
	repeating = missingNumber - S;
 
	return {missingNumber, repeating};

	/*
	TC: O(n)
	SC: O(1)
	*/
}  

```