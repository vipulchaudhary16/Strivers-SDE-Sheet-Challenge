### [Maximum meetings](https://www.codingninjas.com/codestudio/problems/maximum-meetings_8230795?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();

    //{end_time, position, start_time}
    vector<vector<int>> ds(n);

    for(int i = 0; i < n; i++){
        ds[i] = {end[i], i+1, start[i]};
    }

    sort(ds.begin(), ds.end()); //sort according to end time, if end time is same then sort according to position
    vector<int> ans;
    ans.push_back(ds[0][1]);

    int lastEndTime = ds[0][0];

    for(int i = 1; i < n; i++){
        //if starting time of current meeting is less than ending time of last meeting
        if(ds[i][2] > lastEndTime){
            lastEndTime = ds[i][0];
            ans.push_back(ds[i][1]);
        }
    }

    return ans;
    /*
    TC : O(nlogn)
    SC : O(n)
    */
}
```