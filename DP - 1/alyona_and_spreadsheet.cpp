/* During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j we will denote the integer
located at the i-th row and the j-th column. We say that the table is sorted in non-decreasing order in the column j if
ai, j ≤ ai + 1, j for all i from 1 to n - 1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following
question: if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing
order in at least one column? Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1
inclusive.

custom input:
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5

output:
Yes
No
Yes
Yes
Yes
No */


#include <bits/stdc++.h>
#include<climits>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int** arr = new int*[n];

    for(int i=0;i<n;i++)
    {
        arr[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    int** dp_arr = new int*[n];
    int* dp = new int[n];
    for(int i=0;i<n;i++)
    {
        int minimum = INT_MAX;
        dp_arr[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            if(i == 0)
                dp_arr[i][j] = 0;
            else if(arr[i][j] >= arr[i-1][j])
                dp_arr[i][j] = dp_arr[i-1][j];
            else
                dp_arr[i][j] = i;
            if(dp_arr[i][j] < minimum)
                minimum = dp_arr[i][j];
        }
        dp[i] = minimum;
    }

    int k;
    cin>>k;
    while(k--)
    {
        int l,r;
        cin>>l>>r;
        if(dp[r-1] <= l-1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
