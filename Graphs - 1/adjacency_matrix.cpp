#include<bits/stdc++.h>
using namespace std;

void create_graph(int** graph, int n, int e)
{
    for(int i=0;i<e;i++)
    {
        int f,s;
        cout<<"Enter the nodes connected by edge: ";
        cin>>f>>s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
}

void print_graph(int** graph, int* visited, int n, int sv)
{
    if(visited[sv])
        return;

    cout<<sv<<" ";
    visited[sv] = 1;
    for(int i=0;i<=n;i++)
    {
        if(i == sv)
            continue;
        if(graph[sv][i] == 1 && visited[i] == 0)
            print_graph(graph,visited,n,i);
    }
}

int main()
{
    int n,e;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"\nEnter the number of edges: ";
    cin>>e;

    int** graph = new int*[n+1];
    for(int i=0;i<=n;i++)
        graph[i] = new int[n+1]();

    create_graph(graph,n,e);

    int* visited = new int[n+1]();
    print_graph(graph,visited,n,0);

    return 0;
}
