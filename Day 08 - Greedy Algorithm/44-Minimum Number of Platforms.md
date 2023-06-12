### [Minimum Number of Platforms](https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_8230720?challengeSlug=striver-sde-challenge&leftPanelTab=0)

### Approach 1: Brute Force
```cpp
bool compareSecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

int calculateMinPatforms(int at[], int dt[], int n) {
    vector<pair<int, int>> schedule; //(AT, DT)
    for(int i = 0; i < n; i++){
        schedule.push_back({at[i], dt[i]});
    }
    std::sort(schedule.begin(), schedule.end(), compareSecond); //sort by DT

    unordered_map<int, int> platforms; //platform_no -> last DT;
    platforms[1] = schedule[0].second; //first platform

    int p = 1;
    for(int i = 1; i < n; i++){
        int AT = schedule[i].first;
        int DT = schedule[i].second;

        bool flag = false; //if platform is available

        for(auto platform : platforms){
            if(platform.second < AT){ //platform is available
                platforms[platform.first] = DT; //update DT
                flag = true;
                break;
            }
        }

        if(flag == false){ //no platform is available
            p++; //new platform
            platforms[p] = DT;
        }

    }

    return platforms.size(); //no of platforms
} 
/*
Time Complexity: O(n*log(n) + n^2)
Space Complexity: O(n)
*/
```

### Approach 2: Greedy
```cpp
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n); //sort by AT
    sort(dt, dt+n); //sort by DT
    //here we are not using pair because we don't need to know which AT is paired with which DT, we just need to know the count of platforms

    int curr_platform_count = 1, final_platform_count = 1; 
    int curr_at = 1, last_dt = 0; 

    while(curr_at < n and last_dt < n){
        if(at[curr_at] <= dt[last_dt]){ //platform is not available
            curr_platform_count++;
            curr_at++;
        }
        else {  //platform is available
            curr_platform_count--;
            last_dt++;
        }
        final_platform_count = max(final_platform_count, curr_platform_count); //update final count
    }
    
    return final_platform_count;
}
/*
Time Complexity: O(n*log(n))
Space Complexity: O(1)
*/
```