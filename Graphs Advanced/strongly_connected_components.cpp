#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;

void dfs(vector<int>* edges, int sv, unordered_set<int> &visited, stack<int> &s, int n)
{
    visited.insert(sv);
    for(int i=0;i<edges[sv].size();i++)
    {
        if(visited.count(edges[sv][i]) == 0)
            dfs(edges,edges[sv][i],visited,s,n);
    }
    s.push(sv);
}

void dfs2(vector<int>* transpose_edges, int sv, unordered_set<int>* component, unordered_set<int> &visited, int n)
{
    visited.insert(sv);
    for(int i=0;i<transpose_edges[sv].size();i++)
    {
        if(visited.count(transpose_edges[sv][i]) == 0)
            dfs2(transpose_edges,transpose_edges[sv][i],component,visited,n);
    }
    component->insert(sv);
}

unordered_set<unordered_set<int>*>* get_scc(vector<int>* edges, vector<int>* transpose_edges, int n)
{
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    unordered_set<int> visited;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(visited.count(i) == 0)
        {
            dfs(edges,i,visited,s,n);
        }
    }

    /*stack<int> s2 = s;
    while(s2.size() != 0)
    {
        cout<<s2.top();
        s2.pop();
    }
    cout<<endl; */

    visited.clear();
    while(s.size() != 0)
    {
        unordered_set<int>* component = new unordered_set<int>();
        int cur = s.top();
        s.pop();
        if(visited.count(cur) != 0)
            continue;
        dfs2(transpose_edges,cur,component,visited,n);
        output->insert(component);
    }

    return output;
}
int main()
{
    int n;
    cin>>n;
    vector<int>* edges = new vector<int>[n];
    vector<int>* transpose_edges = new vector<int>[n];
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f-1].push_back(s-1);
        transpose_edges[s-1].push_back(f-1);
    }

    unordered_set<unordered_set<int>*>* components = get_scc(edges,transpose_edges,n);

    unordered_set<unordered_set<int>*>::iterator it = components->begin();
    cout<<components->size()<<endl<<endl;
    while(it != components->end())
    {
        unordered_set<int>* component = *it;
        unordered_set<int>::iterator it2 = component->begin();
        while(it2 != component->end())
        {
            cout<<*it2 + 1<<" ";
            it2++;
        }
        it++;
        cout<<endl;
    }

    return 0;
}
