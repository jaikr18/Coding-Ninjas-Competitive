/* Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000).
Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students.
He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible.
Help Shaky in finding out what is the maximum number of candies which a student can get.

custom input:

2
3 2
3 1 4
4 1
3 2 3 9

custom output:

3
9 */

#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

bool is_possible(long long* st, int n, long long ref, long long k)
{
    long long cnt = 0;
    for(int i =0;i<n;i++)
    {
        cnt += (st[i] / ref);
        if(cnt >= k)
            return true;
    }
    return false;
}

void solve(long long* st, int n, long long k)
{
    sort(st,st+n);
    long long min_ans = 0;
    long long max_ans = st[n-1];
    long long ans = 0;
    while(max_ans >= min_ans)
    {
       long long poss_ans = min_ans + (max_ans - min_ans)/2;
        if(is_possible(st,n,poss_ans,k))
        {
            ans = poss_ans;
            min_ans = poss_ans + 1;
        }
        else
            max_ans = poss_ans - 1;
    }
    cout<<ans<<endl;
}

int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long k;
        cin>>k;
        long long* st = new long long[n];
        for(int i=0;i<n;i++)
            cin>>st[i];

        solve(st,n,k);
    }
    return 0;
}
