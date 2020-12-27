#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool ispossible(int board[][9], int row, int col, int check)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col] == check || board[row][i] == check)
            return false;
    }
    int row_check = row - row%3;
    int col_check = col - col%3;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i + row_check][col_check + j] == check)
                return false;
    return true;
}

bool findempty(int board[9][9], int &row, int &col)
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(board[i][j] == 0)
            {
                row = i; col = j;
                return true;
            }
    return false;
}

bool solve(int board[][9])
{
    int row,col;
    if(!findempty(board,row,col))
    {
        return true;
    }
    else
    {
        int check = 1;
        while(check < 10)
        {
            if(ispossible(board,row,col,check))
            {
                board[row][col] = check;
                if(solve(board))
                    return true;
                board[row][col] = 0;
            }
            check++;
        }
        if(check == 10)
            return false;
    }

}

int main()
{
    int board[9][9];
    for(int i=0;i<9;i++)
    {
       string s;
       cin>>s;
       for(int j=0;j<9;j++)
            board[i][j] = s[j] - '0';
    }
    solve(board);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<board[i][j];
        cout<<endl;
    }
    return 0;
}
