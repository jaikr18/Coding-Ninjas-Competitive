#include<bits/stdc++.h>
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void create_graph(int** graph, int n, int e)
{
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
}

vector<int> connected_components(int** graph, int* visited, int n, int e, int sv)
{
    queue<int> pending;
    pending.push(sv);
    vector<int> output;
    while(!pending.empty())
    {
        int cur = pending.front();
        pending.pop();
        output.push_back(cur);
        visited[cur] = 1;
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(graph[cur][i] == 1 && visited[i] == 0)
            {
                pending.push(i);
                visited[i] = 1;
            }
        }
    }
	return output;
}

int main()
{
  	int n, e;
  	cin>>n>>e;
	int** graph = new int*[n];
    for(int i=0;i<n;i++)
        graph[i] = new int[n]();

    create_graph(graph,n,e);

    int* visited = new int[n]();
	int flag = 1;
    int sv = 0;
    while(flag == 1)
    {
        flag = 0;
        vector<int> ans = connected_components(graph,visited,n,e,sv);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                sv = i;
                flag = 1;
            }
        }
    }

  	return 0;
}

