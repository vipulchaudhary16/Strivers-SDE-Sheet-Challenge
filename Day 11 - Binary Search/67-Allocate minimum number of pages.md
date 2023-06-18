### [Allocate minimum number of pages GFG](https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)

```cpp
class Solution 
{
    public:
   bool isPossible(int A[], int N, int pages, int students) {
        int cnt = 0; // number of students allocated
        int sumAllocated = 0; // number of pages allocated to current student
        for (int i = 0; i < N; i++) {
            if (sumAllocated + A[i] > pages) { // if current student cannot be allocated more pages
              cnt++; // then allocate to next student
              sumAllocated = A[i]; // and set the number of pages allocated to current student
              if (sumAllocated > pages) return false; // if number of pages in a book is greater than pages then return false
            } else {
              sumAllocated += A[i]; // else add the number of pages in current book to current student
            }
        }
        if (cnt < students) return true; // if number of students allocated is less than students required then return true
        return false; // else return false
    }
    
    int findPages(int A[], int N, int B) 
    {
        if (B > N) return -1; // if number of students required is greater than number of books then return -1
        int low = A[0]; // minimum number of pages in a book
        int high = 0; // total number of pages in all books
        for (int i = 0; i < N; i++) {
            high = high + A[i];
            low = min(low, A[i]);
        }
        //
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isPossible(A, N, mid, B)) {
              high = mid - 1; // if it is possible to allocate pages to students then try to minimize the number of pages
            } else {
              low = mid + 1; // else try to increase the number of pages
            }
        }
        return low;
    }
};
/*
TC = O(nlogn)
SC = O(1)
*/
```

### [Allocate Books CN](https://www.codingninjas.com/codestudio/problems/allocate-books_8230810?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

bool pos(long long m, vector<int>& v, long long& mx){
	long long i = 0, tot = 0;
	while(m and i < v.size()){
		if(v[i]>mx) return false;
		else{
			if (tot + v[i] <= mx) tot += v[i];
			else{
				m--;
				tot=v[i];
			}
		}
		i++;
	}

	if(m < 1 or i < v.size()){
		return false;
	}
	return true;
}

long long ayushGivesNinjatest(int n, int mm, vector<int>& time) 
{   
    long long high = 0;
    for(int i = 0; i < time.size(); i++) high += time[i];

    long long low = 0, ans = 0;
    while(low <= high){
        long long m = (low + high)/2;
        if(pos(n, time, m)){
            ans = m;
            high = m - 1;
        }
        else{
            low = m + 1;
        }
    }

    return ans;
}
/*
TC = O(nlogn)
SC = O(1)
*/
```