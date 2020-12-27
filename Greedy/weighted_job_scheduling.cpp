/* You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

custom input:
4
3 10 20
1 2 50
6 19 100
2 100 200

output: 250 */

#include<bits/stdc++.h>
using namespace std;
struct jobs
{
    int start;
    int finish;
    int profit;
};

bool sortbysec(const pair<int,pair<int,int>> &x, const pair<int,pair<int,int>> &y)
{
    return ((x.second).first < (y.second).first);
}

bool compare(jobs a, jobs b)
{
    return a.finish < b.finish;
}

int main()
{
    /*int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> jobs;
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        jobs.push_back(make_pair(x,make_pair(y,z)));
    }

    sort(jobs.begin(), jobs.end(), sortbysec);
    int* dp = new int[n];
    dp[0] = jobs[0].second.second;
    for(int i=1;i<n;i++)
    {
        int excluding = dp[i-1], including = jobs[i].second.second;
        for(int j=i-1;j>=0;j--)
        {
           if(jobs[j].second.first <= jobs[i].first)
           {
               including += dp[j];
               break;
           }
        }
        /*int start = 0, end = i-1, poss = 0, flag = 0;
        while(start <= end)
        {
            if(flag == 1)
                break;
            int mid = (start + end)/2;
            if(jobs[mid].second.first < jobs[i].first)
            {
                poss = mid;
                start = mid+1;
            }
            else if(jobs[mid].second.first == jobs[i].first)
            {
                flag = 1;

            }
            else
            {
                for(int k=mid-1;k>=poss;k--)
                {
                    if(jobs[k].second.first <= jobs[i].first)
          			{
               			including += dp[k];
                        flag = 1;
               			break;
           			}
                }
            }
        }
        dp[i] = max(including,excluding);
    }*/

    int n;
    cin>>n;
    jobs* arr = new jobs[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;

    sort(arr,arr+n,compare);
    int* dp = new int[n];
    dp[0] = arr[0].profit;

    for(int i=1;i<n;i++)
    {
        int including = arr[i].profit, excluding = dp[i-1];
        /*for(int j=i-1;j>=0;j--)
        {
            if(arr[j].finish <= arr[i].start)
            {
                including += dp[j];
                break;
            }
        }*/
        int beg = 0, end = i-1, index = -1;
        while(beg <= end)
        {
            int mid = (beg + end)/2;
            if(arr[mid].finish <= arr[i].start)
            {
                if(arr[mid+1].finish <= arr[i].start)
                    beg = mid + 1;
                else
                {
                    index = mid;
                    break;
                }
            }
            else
                end = mid - 1;
        }
        if(index != -1)
            including += dp[index];
        dp[i] = max(including,excluding);
    }
    cout<<dp[n-1]<<endl;

    return 0;
}
