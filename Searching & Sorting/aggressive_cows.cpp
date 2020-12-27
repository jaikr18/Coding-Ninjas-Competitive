/* Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance
between any two of them is as large as possible. What is the largest minimum distance?
custom input: 1
              5 3
            ``1 2 8 4 9
output:       3 */

#include<bits/stdc++.h>
using namespace std;

bool ispossible(int c, long long int* pos, int n, long long int d)
{
    int count = 1;
    long long int last_pos = pos[0];
    for(int i=0;i<n;i++)
    {
        if(pos[i] - last_pos >= d)
        {

            count++;
            last_pos = pos[i];
        }
        if(count == c)
            return true;
    }
    return false;
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        long long int* pos = new long long int[n];
        for(int i=0;i<n;i++)
        {
            cin>>pos[i];
        }
        sort(pos,pos+n);
        long long int start = 0;
        long long int end = pos[n-1] - pos[0];
        long long int ans = -1;
        while(end >= start)
        {
            long long int mid = start + (end-start)/2;
            if(ispossible(c,pos,n,mid))
            {
                ans = mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
