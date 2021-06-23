#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define repf(i, j, k) for (in i = j; i < k; i++)
#define repb(i, j, k) for (in i = j; i > k; i--)
#define endl "\n"
void Dfs(in node, vector<vector<in>> &adj, vector<in> &subtree, vector<in> &height, in parent = 0)
{
    for (auto it : adj[node])
    {
        if (parent != it)
        {
            height[it] += height[node];
            subtree[it] += 1;
            Dfs(it, adj, subtree, height, node);
            subtree[node] += subtree[it];
        }
    }
}
vector<vector<in>> Input(in n, in e)
{

    vector<vector<in>> adj(n + 1);
    repf(i, 0, e)
    {
        in u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
in solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<in>> adj;
    vector<in> subtree(n + 1);
    vector<in> height(n + 1, 1);
    height[0] = 0;
    subtree[1] = 1;
    adj = Input(n, e);

    Dfs(1, adj, subtree, height);
    /*repf(i, 0, n)
    {
        for (auto it : adj[i])
        {

            cout << it << " ";
        }
        cout << endl;
    }*/
    for (auto it : height)
        cout << it << endl;
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
