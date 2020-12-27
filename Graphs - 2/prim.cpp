#include<bits/stdc++.h>
#include<vector>
#include<climits>
#include <iostream>
using namespace std;

int get_min(int* weight, int* visited, int n)
{
    int min_weight = INT_MAX;
    int minel = 0;
    for(int i=1;i<n;i++)
        if(weight[i] < min_weight && visited[i] == 0)
        {
            min_weight = weight[i];
            minel = i;
        }
    return minel;
}

void prim(int** edges, int n, int e)
{
    int* visited = new int[n]();
    int* weight = new int[n]();
    for(int i=1;i<n;i++)
        weight[i] = INT_MAX;

    int* parent = new int[n];
    parent[0] = -1;

    int flag;
    do
    {
    	flag = 0;
        int minel = get_min(weight,visited,n);
        visited[minel] = 1;
        for(int i=0;i<n;i++)
        {
            if(edges[minel][i] > 0 && visited[i] == 0 && edges[minel][i] < weight[i])
            {
                weight[i] = edges[minel][i];
                parent[i] = minel;
            }
        }

        for(int i=0;i<n;i++)
            if(visited[i] == 0)
                flag = 1;

    }while(flag == 1);

    for(int i=1;i<n;i++)
    {
        cout<<min(i,parent[i])<<" ";
        cout<<max(i,parent[i])<<" ";
        cout<<weight[i]<<endl;
    }
}

int main()
{
    int n,e;
    cin>>n>>e;

    int** edges = new int*[n];
    for(int i=0;i<n;i++)
        edges[i] = new int[n]();
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        edges[s][d] = w;
        edges[d][s] = w;
    }

    prim(edges,n,e);

    return 0;
}
