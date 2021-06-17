#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
bool DAG(int idx, vector<int> adj[], vector<int> &visited, vector<int> &revisited)
{
    visited[idx] = 1;
    revisited[idx] = 1;
    for (auto it : adj[idx])
    {
        if (!visited[it])
        {
            visited[it] = 1;
            revisited[it] = 1;
            if(DAG(it, adj, visited, revisited)) return true;
            
        }
        else
        {
            if(visited[it]==revisited[it])
            {
                return true;
            }

        }
    }
    revisited[idx] = 0;
    return false; 
}
bool solve()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    vector<int> visited(n, 0);
    vector<int> revisited(n, 0);
    repf(i, 0, e)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    repf(i, 0, n)
    {
        if (!visited[i])
        {
            if(DAG(i, adj, visited, revisited))return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        if(solve())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
