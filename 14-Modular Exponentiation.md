### [Modular Exponentiation](https://www.codingninjas.com/codestudio/problems/modular-exponentiation_8230803?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force
```cpp
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long long ans = 1;
	long long _x = x;

	for(int i = 1; i <= n; i++) ans = (1LL * ans *x)%m;

	return (int)(ans);
  /*
  TC: O(n) TLE
  SC: O(1)
  */
}
```

#### Optimized (Recursive)

```cpp
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	if(n == 0) return 1;

	int ans = modularExponentiation(x, n/2, m);

	if(n%2 != 0){
		return (1LL*(1LL * ans * ans)%m * x%m)%m;
	} else {
		return (1LL * ans * ans) % m;
	}

	return ans;
}
```

#### Optimized (Iterative)

```cpp
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long long ans = 1;
	long long _x = x; // to avoid overflow

	while(n > 0){
    // if n is odd, multiply ans with x
		if(n%2 != 0){
			ans = ((ans)%m *(_x)%m)%m;
		}
		_x = ((_x)%m * (_x)%m)%m;
    // divide n by 2, to get the next bit
		n/=2;
	}

	return (int)(ans%m);
  /*
  TC: O(logn)
  SC: O(1)
  */
}
```