/* sample input:
10 10
0 3
0 5
0 1
3 2
5 7
1 4
4 7
3 6
6 9
1 8
*/
#include<bits/stdc++.h>
#include <iostream>
#include<vector>
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

bool get_dfs(int** graph, int* visited, int n, int e, int sv, int ev)
{
    visited[sv] = 1;
    for(int i=0;i<n;i++)
    {
        if(graph[sv][i] == 1 && visited[i] == 0)
        {
            if(i == ev)
            {
                output.push_back(ev);
                output.push_back(sv);
                return true;
            }
            bool f = get_dfs(graph,visited,n,e,i,ev);
            if(f)
            {
                output.push_back(sv);
                return true;
            }
        }
    }
    visited[sv] = 0;
    return false;
}

int main()
{
  	int n, e;
  	cin>>n>>e;
	int** graph = new int*[n];
    for(int i=0;i<n;i++)
        graph[i] = new int[n]();

    create_graph(graph,n,e);

    int sv,ev;
    cin>>sv>>ev;
    if(sv == ev)
    {
        cout<<sv<<" ";
        return 0;
    }

    int* visited = new int[n]();
	bool f = get_dfs(graph,visited,n,e,sv,ev);
    if(f)
        for(int i = 0;i<output.size();i++)
            cout<<output[i]<<" ";

  	return 0;
}
