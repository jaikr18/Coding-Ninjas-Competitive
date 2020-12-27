#include<bits/stdc++.h>
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> output;

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

bool isconnected(int** graph, int* visited, int n, int sv)
{
    queue<int> pending;
    pending.push(sv);
    while(!pending.empty())
    {
        int cur =  pending.front();
        pending.pop();
        visited[cur] = 1;
        for(int i=0;i<n;i++)
        {
            if(graph[cur][i] == 1 && visited[i] == 0)
            {
                pending.push(i);
            }
        }
    }

    for(int i=0;i<n;i++)
        if(visited[i] == 0)
            return false;
    return true;
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
	if(!isconnected(graph,visited,n,0))
       cout<<"false";
    else
        cout<<"true";

  	return 0;
}

