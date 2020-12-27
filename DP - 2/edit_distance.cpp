/* Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance
of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform
following three operations only :

1. Delete a character

2. Replace a character with another one

3. Insert a character

custom input:
abc
dc

output: 2 */


#include<iostream>
#include<cstring>
using namespace std;

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
	int m = s1.size(), n = s2.size();
    int** dp = new int*[m+1];
    for(int i=0;i<=m;i++)
        dp[i] = new int[n+1]();

	for(int i=0;i<=n;i++)
        dp[0][i] = i;
    for(int i=0;i<=m;i++)
        dp[i][0] = i;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[m-i] == s2[n-j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }

    int ans = dp[m][n];
    for(int i=0;i<=m;i++)
        delete[] dp[i];
    delete[] dp;

    return ans;
}

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}
