/* Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A)
and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses,
fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.

custom input:
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9

output:
 10 */

#include<climits>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int** arr = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i] = new int[m];
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }

    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++)
        dp[i] = new int[m];

    for(int i=0;i<m;i++)
        dp[0][i] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int cur = arr[i-1][j];
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j] + cur;
                dp[i][j + 1] = dp[i-1][j] + cur;
            }
            else if(j == m-1)
            {
            	dp[i][j-1] = min(dp[i][j-1],dp[i-1][j] + cur);
                dp[i][j] = min(dp[i][j],dp[i-1][j] + cur);
            }
            else
            {
                dp[i][j-1] = min(dp[i][j-1],dp[i-1][j] + cur);
                dp[i][j] = min(dp[i][j],dp[i-1][j] + cur);
                dp[i][j+1] = dp[i-1][j] + cur;
            }
        }
    }

    int minimum = INT_MAX;
    for(int i=0;i<m;i++)
        if(dp[n][i] < minimum)
            minimum = dp[n][i];
    cout<<minimum<<endl;
    return 0;
}
