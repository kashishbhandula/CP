#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
bool CyclicDfs(int idx, vector<int> adj[], vector<int> &visited, int parent)
{
    visited[idx] = 1;
    for (auto it : adj[idx])
    {
        if (!visited[it])
        {

            if (CyclicDfs(it, adj, visited, idx))
                return true;
        }
        else
        {

            if (parent != it)
            {
                return true;
            }
        }
    }
    return false;
}
bool CyclicBfs(int idx, vector<int> adj[], vector<int> &visited)
{
    visited[idx] = 1;
    queue<pair<int, int>> q;
    q.push({idx, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }
            else
            {
                if (parent != it)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int solve()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    vector<int> visited(n, 0);
    repf(i, 0, e)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    repf(i, 0, n)
    {
        if (!visited[i])
        {
            if (CyclicDfs(i, adj, visited, -1))
                return true;
            // if (CyclicBfs(i, adj, visited))
            //    return true
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
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
