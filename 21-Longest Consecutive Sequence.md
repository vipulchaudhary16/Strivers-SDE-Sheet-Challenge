### [Longest Consecutive Sequence](https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence_8230708?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force Approach
```cpp
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    int maxLength = 0;
    int count = 1;

    for(int i = 1; i < n; i++)
    {
        if(arr[i]==arr[i-1])
            continue;
        else if(arr[i] == arr[i-1]+1) // if current element is equal to previous element + 1
            count++;
        else{
            maxLength = max(maxLength, count);
            count = 1; // reset the count
        }
    }
    maxLength = max(maxLength, count);
    return maxLength;
    /*
    Time Complexity: O(NlogN + N) = O(NlogN)
    Space Complexity: O(1)
    */
}
```

#### Optimal Approach
```cpp
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> st; // to store all unique elements
    for(int a: arr) st.insert(a);

    int ans = 0;
    for(int a: arr){
        if(st.count(a-1) == 0){ // means a is the starting element of a sequence
            int curr_ans = 1;
            int curr_a = a;

            while(st.count(curr_a+1)){ // till we find the last element of the sequence
                curr_ans++;
                curr_a++;
            }
            ans = max(ans, curr_ans);
        }
    }

    return ans;
    /*
    Time Complexity: O(N) : Time Complexity for unordered_set::count() method is O(1) in average cases, but in worst case, time complexity can be O(N)
    Space Complexity: O(N)
    */
}
```