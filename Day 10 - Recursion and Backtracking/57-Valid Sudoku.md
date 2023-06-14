### [Valid Sudoku](https://www.codingninjas.com/codestudio/problems/valid-sudoku_8230704?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
bool isSafe(int row, int col, int num, int matrix[9][9]){
  for(int i = 0; i < 9; i++){
    if(matrix[row][i] == num)  //check row wise 
      return false;
    if(matrix[i][col] == num)  //check column wise
      return false;
    if(matrix[3*(row/3) + i/3][3*(col/3) + i%3] == num)  //check sub grid
      return false;
  }
  return true; //safe
}

bool isItSudoku(int matrix[9][9]) {
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(matrix[i][j] == 0){ //empty cell
        for(int num = 1; num <= 9; num++){ //try all possible numbers
          if(isSafe(i, j, num, matrix)){ //if it is safe to place num at (i, j)
            matrix[i][j] = num; //place num at (i, j)
            if(isItSudoku(matrix)) return true; //find the solution for the remaining board
            else matrix[i][j] = 0; //backtrack
          }
        }
        return false; //no number can be placed at (i, j)
      }
    }
  }
  return true; //sudoku solved
}
/*
TC = O(9^(n*n))
SC = O(n*n)
*/

```