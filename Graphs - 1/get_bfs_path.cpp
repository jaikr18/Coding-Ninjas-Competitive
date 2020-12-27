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
#include<unordered_map>
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

bool get_bfs(int** graph, int* visited, int n, int e, int sv, int ev)
{
    queue<int> pending;
    pending.push(sv);
    unordered_map<int,int> m;
    while(!pending.empty())
    {
        int cur = pending.front();
        pending.pop();
        visited[cur] = 1;
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(graph[cur][i] == 1 && visited[i] == 0)
            {
                pending.push(i);
                m[i] = cur;
                visited[i] = 1;
                if(pending.back() == ev)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            break;
    }

    if(m.count(ev) > 0)
    {
        unordered_map<int,int>:: iterator it = m.find(ev);
        while(it->second != sv)
        {
            output.push_back(it->first);
            it = m.find(it->second);
        }
        output.push_back(it->first);
        output.push_back(it->second);
        return true;
    }
    else return false;
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
    if(graph[sv][ev] == 1)
    {
        cout<<ev<<" "<<sv<<" ";
        return 0;
    }

    int* visited = new int[n]();
	bool f = get_bfs(graph,visited,n,e,sv,ev);
    if(f)
        for(int i = 0;i<output.size();i++)
            cout<<output[i]<<" ";

  	return 0;
}
