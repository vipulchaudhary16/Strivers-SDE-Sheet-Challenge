### [Find Nth Root Of M](https://www.codingninjas.com/codestudio/problems/find-nth-root-of-m_8230799?challengeSlug=striver-sde-challenge)

```cpp
int NthRoot(int n, int m) {
  int low = 1, high = m; // low = 1, high = m because the root will always be between 1 and m
  while(low <= high){ // binary search
    int mid = low + (high-low)/2; // mid = (low+high)/2

    if(pow(mid, n) == m) return mid; // if mid^n == m, return mid
    else if(pow(mid, n) > m) high = mid-1; // if mid^n > m, search in the left half
    else low = mid+1; // if mid^n < m, search in the right half
  }

  return -1;
}
/*
TC: O(log(m))
SC: O(1)
*/
```