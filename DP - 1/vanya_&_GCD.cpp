/* Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences
of this array with length ≥1 and GCD=1. A sub-sequence of an array is obtained by deleting some (or none) elements
and maintaining the relative order of the rest of the elements. As the answer may be large, print it Modulo 10^9+7 */

#include <bits/stdc++.h>
#include<climits>
#include<algorithm>
using namespace std;


int mod = pow(10,9) + 7;
int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    long long** dp = new long long*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new long long[max+1];
        for(int j=0;j<=max;j++)
            dp[i][j] = 0;
    }

    dp[0][arr[0]] = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i] > arr[j])
            {
                for(int g=1;g<=arr[j];g++)
                {
                    int ng = __gcd(arr[i],g);
                    dp[i][ng] = (dp[i][ng] + dp[j][g])%mod;;
                }
            }
        }
        dp[i][arr[i]]++;
    }

    long long ans = 0;
    for(int i=0;i<n;i++)
        ans = (ans + dp[i][1])%mod;

    cout<<ans%mod<<endl;

    return 0;
}
