/*Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his
permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.

Input format: The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi.
The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers
ai and bi.

Sample input:
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4

Output:
NO
YES
*/


#include<bits/stdc++.h>
#include<utility>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> component(int** graph, int* visited, int n, int m, int sv)
{
    vector<int> output;
    queue<int> pending;
    pending.push(sv);

    while(!pending.empty())
    {
        int cur = pending.front();
        pending.pop();
        visited[cur] = 1;
        output.push_back(cur);
        for(int i=1;i<=n;i++)
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

vector<int>* return_components(int** graph, int n, int m, int &cnt)
{
    vector<int>* components = new vector<int>[n];
    int* visited = new int[n+1]();

    int flag;
    do
    {
        flag = 0;
        for(int i=1;i<=n;i++)
        {
            if(visited[i] == 0)
            {
                flag = 1;
                components[cnt++] = component(graph,visited,n,m,i);
            }
        }
    }while(flag == 1);

    return components;
}

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
    	int n,m;
        cin>>n>>m;
        int* p = new int[n];
        int* q = new int[n];
        for(int i=0;i<n;i++)
        	cin>>p[i];
        for(int i=0;i<n;i++)
			cin>>q[i];

        int** graph = new int*[n+1];
        for(int i=0;i<=n;i++)
            graph[i] = new int[n+1]();

        for(int i=0;i<m;i++)
        {
            int f,s;
            cin>>f>>s;
            graph[f][s] = 1;
            graph[s][f] = 1;
        }

        int cnt = 0;
        vector<int>* components = return_components(graph,n,m,cnt);

        int flag = 0;
        for(int i=0;i<cnt;i++)
        {
            unordered_map<int,int> p_map;
            for(int j=0;j<components[i].size();j++)
                p_map[p[components[i][j] - 1]] = 1;

            for(int j=0;j<components[i].size();j++)
            {
                if(p_map.count(q[components[i][j] - 1]) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }

        /*for(int i=0;i<cnt;i++)
        {
            for(int j=0;j<components[i].size();j++)
            {
                cout<<components[i][j]<<" ";
            }
            cout<<endl;
        }*/

        if(flag == 1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;

        delete [] p;
        delete [] q;
        for(int i=0;i<=n;i++)
            delete [] graph[i];
        delete[] graph;
        delete[] components;
    }

	return 0;
}
