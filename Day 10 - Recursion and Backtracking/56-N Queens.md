### [N Queens](https://www.codingninjas.com/codestudio/problems/n-queens_8230707?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
bool isSafe(int row, int col, int n, vector<vector<int>> &board){
    int _row = row, _col = col;

    //upper diagonal
    while(row >= 0 and col >= 0){
        if(board[row][col] == 1) return false;
        row--;
        col--;
    }

    row = _row, col = _col;
    //lower diagonal
    while(col >= 0 and row < n){
        if(board[row][col] == 1) return false;
        row++;
        col--;
    }

    //same row
    row = _row, col = _col;
    while(col >= 0){
        if(board[row][col] == 1) return false;
        col--;
    }

    return true; //safe
}

void f(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans){
    if(col == n){
        //add to ans
        vector<int> temp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }

    for(int row = 0; row < n; row++){
        if(isSafe(row, col, n, board)){
            board[row][col] = 1; //place the queen
            f(col+1, n, board, ans); //find the solution for the remaining board
            board[row][col] = 0; //backtrack
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0)); //empty board
    vector<vector<int>> ans; //to store the result
    f(0, n, board, ans);
    return ans;
}
/*
TC = O(n*n!)
SC = O(n*n!) // for storing the result
```