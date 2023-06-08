### [Merge Intervals](https://www.codingninjas.com/codestudio/problems/merge-intervals_8230700?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end()); // sort the intervals according to the start 

    int start = intervals[0][0], end = intervals[0][1];

    for(auto pair: intervals){
        if(pair[0] <= end){ // if the start of the current interval is less than or equal to the end of the previous interval then merge them
            end = max(end, pair[1]);
        } else {
            ans.push_back({start, end}); // if the start of the current interval is greater than the end of the previous interval then push the previous interval to the answer vector and update the start and end
            start = pair[0];
            end = pair[1];
        }
    }
    ans.push_back({start, end}); // push the last interval to the answer
    return ans;
    /*
    TC: O(nlogn + n)
    SC: O(n) // if we consider the space required for the answer vector
    */
}
```
