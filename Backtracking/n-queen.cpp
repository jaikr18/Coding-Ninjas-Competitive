#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool ispossible(int n, int row, int col)
{
    for(int i=0;i<row;i++)
    {
        if(board[i][col] == 1)
            return false;
        for(int j=0;j<n;j++)
        {
            if((i+j == row+col && board[i][j] == 1) || (row-i == col-j && board[i][j] == 1))
                return false;
        }
    }
    return true;

}

void queen(int n, int row)
{
    if(row == n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<" ";
        cout<<endl;
    }
    for(int j=0;j<n;j++)
    {
        if(ispossible(n,row,j))
        {
            board[row][j] = 1;
            queen(n,row+1);
            board[row][j] = 0;
        }
    }
    return;
}

void place_n_queen(int n)
{
    memset(board,0,11*11*sizeof(int));
    queen(n,0);
}

int main()
{
    int n;
    cin>>n;
    place_n_queen(n);
    return 0;
}
