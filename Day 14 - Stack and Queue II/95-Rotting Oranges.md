### [Rotting Oranges](https://www.codingninjas.com/studio/problems/rotting-oranges_8230701?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include<bits/stdc++.h>

struct node{
    int row;
    int col;
    int time;

    node(int row, int col, int time){
        this->row = row;
        this->col = col;
        this->time = time;
    }
};

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<node *> q;
    vector<vector<bool>> rotten(n, vector<bool>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                //rotten orange
                q.push(new node(i, j, 0));
                rotten[i][j] = true;
            }
        }
    }

    int ans = 0;
    vector< pair<int, int> > directions;
    directions.push_back({0, 1}); //RIGHT
    directions.push_back({0, -1}); //LEFT
    directions.push_back({1, 0}); //DOWN
    directions.push_back({-1, 0}); //UP

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int row = front->row;
        int col = front->col;
        int time = front->time;
        ans = max(ans, time);

        for(int i = 0; i < directions.size(); i++){
            int next_row = row + directions[i].first;
            int next_col = col + directions[i].second;

            if(next_row >= 0 && next_row < n
                && next_col >= 0 && next_col < m
                && !rotten[next_row][next_col]
                && grid[next_row][next_col] == 1){
                    q.push(new node(next_row, next_col, time+1));
                    rotten[next_row][next_col] = true;
                }

        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1 and !rotten[i][j]) return -1;
        }
    }

    return ans;
}
```