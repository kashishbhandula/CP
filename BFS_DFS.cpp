#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
void dfs(vector<int> adj[], int node, vector<int> &visited, vector<int> &df)
{
    df.push_back(node);
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(adj, it, visited, df);
        }
    }
}
void solve()
{
    int n, e;
    cin >> n >> e;
    //adjacentList
    vector<int> adj[n + 1];
    vector<int> visited(n + 1, 0);
    repf(i, 0, e)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    /*repf(i, 1, n + 1)
    {
        for (auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }*/

    //Adjoint Matrix/
    /* int adj[n+1][n+1];
    memset(adj,int,sizeof(adj));
    repf(i,0,n)
    { 
        int u,v;
        cin>>u>>v>;
        adj[u][v]=1;
        adj[v][u]=1;

    }*/

    //BFS
    queue<int> q;
    vector<int> bfs;
    repf(i, 1, n + 1)
    {
        if (!(visited[i]))
        {
            q.emplace(i);
            visited[i] = 1;
            while (!(q.empty()))
            {
                int node = q.front();
                q.pop();
                bfs.emplace_back(node);
                for (auto it : adj[node])
                {
                    if (!(visited[i]))
                    {
                        q.emplace(it);
                        visited[i] = 1;
                    }
                }
            }
        }
    }

    //Dfs
   /* vector<int> df;
    repf(i, 1, n + 1)
    {
        if (!visited[i])
        {
            dfs(adj, i, visited, df);
        }
    }*/

    for (auto i : bfs)
    {
        cout << i << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
}
