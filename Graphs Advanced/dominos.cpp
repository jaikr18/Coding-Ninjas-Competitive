#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
#include<utility>
using namespace std;

bool compare(pair<int,vector<int>> &p1, pair<int,vector<int>> &p2)
{
    return p1.second.size() < p2.second.size();
}

void dfs(vector<int>* edges, int sv, int index, unordered_set<int> &visited, pair<int,vector<int>>* effect)
{
    visited.insert(sv);
    for(int i=0;i<edges[sv].size();i++)
    {
        if(visited.count(edges[sv][i]) == 0)
            dfs(edges,edges[sv][i],index,visited,effect);
    }
    if(sv != index)
        effect[index].second.push_back(sv);
}

void fill_domino(vector<int>* edges, int sv, int index, unordered_set<int> &visited, pair<int,vector<int>>* effect)
{
    effect[index].first = sv;
    dfs(edges,sv,index,visited,effect);
}

void dominos(vector<int>* edges, int n)
{
    pair<int,vector<int>>* effect = new pair<int,vector<int>>[n]();
    for(int i=0;i<n;i++)
    {
        unordered_set<int> visited;
        fill_domino(edges,i,i,visited,effect);
    }

    sort(effect,effect+n,compare);

    /* for(int i=0;i<n;i++)
    {
        cout<<effect[i].first<<" -> ";
        for(int j=0;j<effect[i].second.size();j++)
            cout<<effect[i].second[j]<<" ";
        cout<<endl;
    } */

    unordered_set<int> fallen;
    int cnt = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(fallen.count(effect[i].first) == 0)
        {
            cnt++;
            fallen.insert(effect[i].first);
            for(int j=0;j<effect[i].second.size();j++)
            {
                if(fallen.count(effect[i].second[j]) == 0)
                    fallen.insert(effect[i].second[j]);
            }
        }
    }
    cout<<cnt<<endl;
}


int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>* edges = new vector<int>[n];
        for(int i=0;i<m;i++)
        {
            int f,s;
            cin>>f>>s;
            edges[f-1].push_back(s-1);
        }

        dominos(edges,n);

    }
	return 0;
}
