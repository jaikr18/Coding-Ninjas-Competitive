#include <iostream>
#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;

class edge
{
public:
    int source;
    int dest;
    int weight;
};

bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

int get_parent(int* parent, int v)
{
    while(parent[v] != v)
    {
        v = parent[v];
    }
    return v;
}

void kruskal(edge* edges, int n, int e)
{

    int cnt = 0, index = 0;
    int* parent = new int[n];
    for(int i=0;i<n;i++)
        parent[i] = i;
    vector<edge> output;
    while(cnt < n-1)
    {
        edge cur = edges[index];
        int source_parent = get_parent(parent,cur.source);
        int dest_parent = get_parent(parent,cur.dest);
        if(source_parent != dest_parent)
        {
            cnt++;
            output.push_back(cur);
            parent[dest_parent] = source_parent;
        }
        index++;
    }

    for(int i=0;i<output.size();i++)
    {
        cout<<min(output[i].source,output[i].dest)<<" ";
        cout<<max(output[i].dest,output[i].source)<<" ";
        cout<<output[i].weight<<endl;
    }
}

int main()
{
    int n,e;
    cin>>n>>e;

    edge* edges = new edge[e];
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].source = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }

    sort(edges,edges+e,compare);
    kruskal(edges,n,e);

    return 0;
}
