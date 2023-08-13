#include <iostream>
#define N 9
using namespace std;
int grid[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
{5, 2, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 0, 0, 3, 1},
{0, 0, 3, 0, 1, 0, 0, 8, 0},
{9, 0, 0, 8, 6, 3, 0, 0, 5},
{0, 5, 0, 0, 9, 0, 6, 0, 0},
{1, 3, 0, 0, 0, 0, 2, 5, 0},
{0, 0, 0, 0, 0, 0, 0, 7, 4},
{0, 0, 5, 2, 0, 6, 3, 0, 0}};
bool isPresentInCol(int col, int num){
for (int row = 0; row < N; row++)
if (grid[row][col] == num)
return true;
return false;
}
bool isPresentInRow(int row, int num){
for (int col = 0; col < N; col++)
if (grid[row][col] == num)
return true;
return false;
}
bool isPresentInBox(int rowstarting, int colstarting, int num){
for (int row = 0; row < 3; row++)
for (int col = 0; col < 3; col++)
if (grid[row+rowstarting][col+colstarting] == num)
return true;
return false;
}
void sudokuGrid(){
for (int row = 0; row < N; row++){
for (int col = 0; col < N; col++){
if(col == 3 || col == 6)
cout << " | ";
cout << grid[row][col] <<" ";
}
if(row == 2 || row == 5){
cout << endl;
for(int i = 0; i<N; i++)
cout << "---";
}
cout << endl;
}
}
bool findEmptyPlace(int &row, int &col){ //we will find empty location and update row and column
for (row = 0; row < N; row++)
for (col = 0; col < N; col++)
if (grid[row][col] == 0) //empty = 0
return true;
return false;
}
bool isValidPlace(int row, int col, int num){
//when number is not found in col, row and current box
return !isPresentInRow(row, num) && !isPresentInCol(col, num) &&
!isPresentInBox(row - row%3 , col - col%3, num);
}
bool solveSudoku(){
int row, col;
if (!findEmptyPlace(row, col))
return true; //if all places are filled
for (int num = 1; num <= 9; num++){
if (isValidPlace(row, col, num)){ //check if conditions are met
grid[row][col] = num;
if (solveSudoku()) // go for others in the grid
return true;
grid[row][col] = 0; //turn to unassigned space when conditions are not completed
}
}
return false;
}
int main(){
if (solveSudoku() == true)
sudokuGrid();
else
cout << "No solution exists";
}