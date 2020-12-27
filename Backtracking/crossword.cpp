#include<bits/stdc++.h>
#include<iostream>
using namespace std;
char grid[10][10];

void setvertical(string word, int row, int col, bool* helper)
{
    for(int i=row,j=0;j<word.length();i++,j++)
    {
        if(grid[i][col] == '-')
        {
            helper[j] = true;
            grid[i][col] = word[j];
        }
        else if(grid[i][col] == word[j])
        {
            helper[j] = false;
            grid[i][col] = word[j];
        }
    }
}

void sethorizontal(string word, int row, int col, bool* helper)
{
    for(int i=col,j=0;j<word.length();i++,j++)
    {
        if(grid[row][i] == '-')
        {
            helper[j] = true;
            grid[row][i] = word[j];
        }
        else if(grid[row][i] == word[j])
        {
            helper[j] = false;
            grid[row][i] = word[j];
        }
    }
}

bool isvalidhorizontal(string word, int row, int col)
{
    if(word.length() > 10 - col)
        return false;
    for(int i=col,j=0;j<word.length();i++,j++)
    {
        if(grid[row][i] != '-' && grid[row][i] != word[j])
            return false;
    }
    return true;
}

bool isvalidvertical(string word, int row, int col)
{
    if(word.length() > 10 - row)
        return false;
    for(int i=row,j=0;j<word.length();i++,j++)
    {
        if(grid[i][col] != '-' && grid[i][col] != word[j])
            return false;
    }
    return true;
}

void resethorizontal(int row, int col, bool helper[], int len)
{
    for(int i=0,j=col;i<len;i++,j++)
        if(helper[i] == true)
            grid[row][j] = '-';
}

void resetvertical(int row, int col, bool helper[], int len)
{
    for(int i=0,j=row;i<len;i++,j++)
       if(helper[i] == true)
           grid[j][col] = '-';
}

bool crossword(string word[], int count, int index)
{
    if(index == count)
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
                cout<<grid[i][j];
            cout<<endl;
        }
        return true;
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(grid[i][j] == '-' || grid[i][j] == word[index][0])
            {
                int len = word[index].size();
                bool helper[len];
                for(int i=0;i<len;i++)
                    helper[i] = false;

                if(isvalidvertical(word[index],i,j))
                {
                    setvertical(word[index],i,j,helper);
                    if(crossword(word,count,index+1))
                        return true;
                    resetvertical(i,j,helper,len);
                }

                if(isvalidhorizontal(word[index],i,j))
                {
                    sethorizontal(word[index],i,j,helper);
                    if(crossword(word,count,index+1))
                        return true;
                    resethorizontal(i,j,helper,len);
                }
            }
        }
    }
    return false;
}

void solve(string word[10], int count)
{
    bool temp =



    crossword(word,count,0);
    return;
}

int main() {

	// Write your code here
    string s;
    for(int i=0;i<10;i++)
    {
        cin>>s;
        for(int j=0;j<10;j++)
            grid[i][j] = s[j];
    }
    string s1;
    cin>>s1;
    string temp = "";
    string word[10];
    int count = 0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i] == ';')
        {
            word[count++] = temp;
            temp = "";
        }
        else
            temp += s1[i];
    }
    word[count++] = temp;

    solve(word,count);

    return 0;
}
