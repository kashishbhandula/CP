#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define repf(i, j, k) for (in i = j; i < k; i++)
#define repb(i, j, k) for (in i = j; i > k; i--)
#define endl "\n"
in Par[100005][17];
in BinaryLifting(in u, in v, in idx = 16)
{
    while (idx >= 0)
    {
        if (Par[u][idx] != Par[v][idx])
        {
            u = Par[u][idx];
            v = Par[v][idx];
        }

        idx--;
    }
    return u;
}
in Find(in node, in k)
{
    repf(i, 0, 17)
    {
        if (k & (1 << i))
        {
            node = Par[node][i];
        }
    }
    if(node==0)return -1;
    return node;
}
void Dfs(in node, vector<vector<in>> &adj,vector<in>&height, in parent = 0)
{
    Par[node][0] = parent;
    repf(i, 1, 17)
    {
        Par[node][i] = Par[Par[node][i - 1]][i - 1];
    }
    for (auto it : adj[node])
    {
        if (it != parent)
        {
            height[it]+=height[node];
            Dfs(it, adj,height, node);
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
    in n, e, q;
    cin >> n >> e >> q;
    vector<vector<in>> adj = Input(n, e);
    vector<in>height(n+1,1);
    height[0]=0;
    Dfs(1, adj,height);
    while (q--)
    {
        in u, v;
        cin >> u >> v;
        in Min = (height[u], height[v]);
        u = Find(u, height[u] - Min);
        v = Find(v, height[v] - Min);
        cout << Find(BinaryLifting(u, v), 1) << endl;
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
