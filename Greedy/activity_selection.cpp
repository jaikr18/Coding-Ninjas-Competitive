/* You are given n activities with their start and finish times. Select the maximum number of activities that can be
performed by a single person, assuming that a person can only work on a single activity at a time.

custom input:
6
1 2
3 4
0 6
5 7
8 9
5 9

output:
4 */

#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &x, const pair<int,int> &y)
{
    return (x.second < y.second);
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> times;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        times.push_back(make_pair(x,y));
    }

    sort(times.begin(), times.end(), sortbysec);
    int count = 0, cur = 0;

    for(int i=0;i<n;i++)
    {
    	 if(times[i].first >= cur)
         {
             cur = times[i].second;
             count++;
         }
    }

    cout<<count<<endl;

    return 0;
}
