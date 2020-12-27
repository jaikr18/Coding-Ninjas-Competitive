// Problem code: CHEFRES

#include<bits/stdc++.h>
#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> intervals;
    int* arrivals = new int[m];
    for(int i=0;i<n;i++)
    {
        int o,c;
        cin>>o>>c;
        intervals.push_back(make_pair(o,c));
    }
    sort(intervals.begin(),intervals.end());
    while(m--)
    {
        int curr;
        cin>>curr;
        int index = lower_bound(intervals.begin(),intervals.end(),make_pair(curr,0)) - intervals.begin();
        if(index == 0)
        {
            int ans = intervals[index].first - curr;
            cout<<ans<<endl;
        }
        else
        {
            int ans = -1;
            if(intervals[index - 1].second > curr)
                ans = 0;
            else if(index < intervals.size())
                ans = intervals[index].first - curr;
            cout<<ans<<endl;
        }
    }

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
