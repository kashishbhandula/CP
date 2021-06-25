#include <bits/stdc++.h>
using namespace std;
#define in long long int
#define ll int
#define repf(i, j, k) for (in i = j; i < k; i++)
#define repb(i, j, k) for (in i = j; i > k; i--)
#define endl "\n"
in Par[200018][20];
void Dfs(in node, vector<vector<in>> &adj, vector<in> &height, in parent = 0)
{
    Par[node][0] = parent;
    repf(i, 1, 20)
    {
        Par[node][i] = Par[Par[node][i - 1]][i - 1];
    }
    for (auto it : adj[node])
    {
        if (parent != it)
        {
            height[it] += height[node];
            Dfs(it, adj, height, node);
        }
    }
}
in Find(in node, in k)
{
    repf(i, 0, 20)
    {
        if (k & (1 << i))
        {
            node = Par[node][i];
        }
    }
    if (node == 0)
        return -1;
    return node;
}
in BinaryLifting(in u, in v, vector<in> &height, in idx = 19)
{
    if (height[u] > height[v])
        swap(u, v);
    in diff = height[v] - height[u];
    v = Find(v, diff);
    if (u == v)
        return v;

    while (idx >= 0)
    {
        if (Par[u][idx] != Par[v][idx])
        {
            u = Par[u][idx];
            v = Par[v][idx];
        }

        idx--;
    }
    return Par[u][0];
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
void solve()
{
    in n, e, q;
    cin >> n >> q;
    e = n - 1;

    vector<vector<in>> adj;
    vector<in> height(n + 1, 1);
    height[0] = 0;
    adj = Input(n, e);
    Dfs(1, adj, height);
    while (q--)
    {
        in u, v;
        cin >> u >> v;

        in common = BinaryLifting(u, v, height);
        //cout << height[u]<<" "<<height[v]<<" "<<common << endl;
        if (common == u || common == v)
        {
            cout << abs(height[u] - height[v]) << endl;
        }
        else
        {
            cout << abs(height[u] + height[v] - (2 * height[common])) << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
