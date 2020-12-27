#include<bits/stdc++.h>
#include<climits>
#include <iostream>
using namespace std;

int get_min(int* distance, int* visited, int n)
{
    int min_distance = INT_MAX;
    int minel = 0;
    for(int i=0;i<n;i++)
    	if(visited[i] == 0 && distance[i] < min_distance)
        {
            min_distance = distance[i];
            minel = i;
        }
    return minel;
}

bool condition(int* visited, int n)
{
    for(int i=0;i<n;i++)
        if(visited[i] == 0)
            return true;
    return false;
}

void dijkstra(int** graph, int n, int e)
{
    int* visited = new int[n]();
    int* distance = new int[n]();
    for(int i=1;i<n;i++)
        distance[i] = INT_MAX;

    while(condition(visited,n))
    {
        int minel = get_min(distance,visited,n);
        visited[minel] = 1;
        for(int i=0;i<n;i++)
        {
            if(graph[minel][i] > 0 && visited[i] == 0 && (distance[minel] + graph[minel][i] < distance[i]))
            {
                distance[i] = distance[minel] + graph[minel][i];
            }
        }
    }

    for(int i=0;i<n;i++)
    	cout<<i<<" "<<distance[i]<<endl;
}

int main()
{
    cout<<"\t\tDIJKSTRA'S ALGORITHM"<<endl<<endl;
    int n,e;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"\nEnter the number of edges: ";
    cin>>e;

    int** graph = new int*[n];
    for(int i=0;i<n;i++)
        graph[i] = new int[n]();

    for(int i=0;i<e;i++)
    {
        printf("\nEnter the data for edge %d (source, dest, distance): ",i+1);
        int s,d,dist;
    	cin>>s>>d>>dist;
        graph[s][d] = dist;
        graph[d][s] = dist;
    }

    cout<<"\n\nThe minimum distances from source to other vertices are (destination, distance):\n";
    dijkstra(graph,n,e);
    return 0;
}
