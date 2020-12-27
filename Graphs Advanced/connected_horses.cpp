#include<bits/stdc++.h>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

long long factorial(int n)
{
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}

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

vector<int>* return_components(int** graph, int n, int m, int &cnt)
{
    vector<int>* components = new vector<int>[n];
    int* visited = new int[n]();

    int flag;
    do
    {
        flag = 0;
        for(int i=0;i<n;i++)
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
        int n,m,q;
        cin>>n>>m>>q;
        int** board = new int*[n];
        for(int i=0;i<n;i++)
        {
            board[i] = new int[m];
            for(int j=0;j<m;j++)
                board[i][j] = -1;
        }

        for(int i=0;i<q;i++)
        {
            int h1,h2;
            cin>>h1>>h2;
            board[h1-1][h2-1] = i;
        }

        int* visited = new int[q]();
        int** graph = new int*[q];
        for(int i=0;i<q;i++)
            graph[i] = new int[q]();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] > -1)
                {
                    int cur = board[i][j];

                    if((i+2 < n) && (j+1 < m) && (board[i+2][j+1] > -1))
                        graph[cur][board[i+2][j+1]] = 1;

                    if((i+2 < n) && (j-1 >= 0) && (board[i+2][j-1] > -1))
                        graph[cur][board[i+2][j-1]] = 1;

                    if((i-2 >= 0) && (j+1 < m) && (board[i-2][j+1] > -1))
                        graph[cur][board[i-2][j+1]] = 1;

                    if((i-2 >= 0) && (j-1 >= 0) && (board[i-2][j-1] > -1))
                        graph[cur][board[i-2][j-1]] = 1;

                    if((j+2 < m) && (i+1 < n) && (board[i+1][j+2] > -1))
                        graph[cur][board[i+1][j+2]] = 1;

                    if((j+2 < m) && (i-1 >= 0) && (board[i-1][j+2] > -1))
                        graph[cur][board[i-1][j+2]] = 1;

                    if((j-2 >= 0) && (i+1 < n) && (board[i+1][j-2] > -1))
                        graph[cur][board[i+1][j-2]] = 1;

                    if((j-2 >= 0) && (i-1 >= 0) && (board[i-1][j-2] > -1))
                        graph[cur][board[i-1][j-2]] = 1;

                }
            }
        }

        for(int i=0;i<q;i++)
        {
            for(int j=0;j<q;j++)
                cout<<graph[i][j]<<" ";
            cout<<endl;
        }

        long long ans = 1;
        int cnt = 0;
        vector<int>* components = new vector<int>[q+1];
        components = return_components(graph,q,0,cnt);
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
            cout<<components[i].size()<<" ";

        for(int i=0;i<cnt;i++)
        {
            int component_size = components[i].size();
            long long component_combinations = factorial(component_size);
            ans *= component_combinations;
        }
        long long mod = pow(10,9) + 7;
        ans = ans % mod;
        cout<<ans<<endl;
    }
	return 0;
}
