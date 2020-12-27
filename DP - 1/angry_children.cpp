#include <bits/stdc++.h>
#include<climits>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int* packets = new int[n];
    for(int i=0;i<n;i++)
        cin>>packets[i];

    sort(packets, packets+n);

    int* sum =  new int[n];
    for(int i=0;i<n;i++)
        sum[i] = packets[i];

    int* dp = new int[n];
    dp[0] = 0;
    int i=1, minimum = INT_MAX;
    for(i;i<k;i++)
    {
        sum[i] += sum[i-1];
        dp[i] = dp[i-1] + i*packets[i] - sum[i-1];
    }
    if(dp[i-1] < minimum)
        minimum = dp[i-1];

    for(i;i<n;i++)
    {
        sum[i] += sum[i-1] - packets[i-k];
        dp[i] = dp[i-1] - sum[i-1] + packets[i-k] + (k-1)packets[i-k] + (k-1)packets[i];
        if(dp[i] < minimum)
            minimum = dp[i];
    }

    cout<<minimum<<endl;

    return 0;
}
