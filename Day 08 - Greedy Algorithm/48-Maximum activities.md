### [Maximum activities](https://www.codingninjas.com/codestudio/problems/maximum-activities_8230800?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<algorithm>
#include<vector>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int>> activities; //{finish, start}
    
    int n = start.size();
    for(int i = 0; i < n; i++){
        activities.push_back({finish[i], start[i]});
    }
    sort(activities.begin(), activities.end()); //sort according to finish time

    int lastActivityEndsAt = activities[0].first; //first activity will always be selected

    int maxActivities = 1;
    for(int i = 1; i < n; i++){
        if(lastActivityEndsAt <= activities[i].second){ //if start time of current activity is greater than or equal to end time of last activity
            lastActivityEndsAt = activities[i].first;
            maxActivities++;
        }
    }

    return maxActivities;
    /*
    Time Complexity: O(nlogn)
    Space Complexity: O(n)
    */
}
```