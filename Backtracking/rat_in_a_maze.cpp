#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solution[20][20];

void solve(int maze[][20], int n, int row, int col)
{
    if(row == n-1 && col == n-1)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<solution[i][j]<<" ";
        cout<<endl;
        return;
    }
    if(row-1 >= 0 && maze[row-1][col] == 1 && solution[row-1][col] == 0)
    {
        solution[row-1][col] = 1;
        solve(maze,n,row-1,col);
        solution[row-1][col] = 0;
    }
    if(col+1 < n && maze[row][col+1] == 1 && solution[row][col+1] == 0)
    {
        solution[row][col+1] = 1;
        solve(maze,n,row,col+1);
        solution[row][col+1] = 0;
    }
    if(row+1 < n && maze[row+1][col] == 1 && solution[row+1][col] == 0)
    {
        solution[row+1][col] = 1;
        solve(maze,n,row+1,col);
        solution[row+1][col] = 0;
    }
    if(col-1 >= 0 && maze[row][col-1] == 1 && solution[row][col-1] == 0)
    {
        solution[row][col-1] = 1;
        solve(maze,n,row,col-1);
        solution[row][col-1] = 0;
    }
    return;
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
	memset(solution,0,20*20*sizeof(int));
    solution[0][0] = 1;
    solve(maze,n,0,0);
}

int main(){

  int n;
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }
  }
  ratInAMaze(maze, n);
}


