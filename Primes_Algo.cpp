#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
void MSP(int n, vector<vector<pair<int, int>>> &adj)
{
    vector<int> key(n, INT_MAX);
    vector<bool> msp(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    //parent[0] = -1;
    key[0] = 0;

    repf(i, 0, n - 1)
    {
        int node = pq.top().second;
        msp[node] = true;
        pq.pop();
        for (auto it : adj[node])
        {
            if (!msp[it.first])
            {
                if (it.second < key[it.first])
                {
                    key[it.first] = it.second;
                    parent[it.first] = node;
                    pq.push({it.second, it.first});
                }
            }
        }
    }
    repf(i, 0, n)
    {
        cout << i << " " << parent[i] << " " << key[i] << endl;
    }
}
vector<vector<pair<int, int>>> Input(int n, int e)
{

    vector<vector<pair<int, int>>> adj(n);
    repf(i, 0, e)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}
int solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adj;
    adj = Input(n, e);
    /*repf(i,0,n)
    {
        
        for(auto it:adj[i])
        {
            cout<<i<<" "<<it.first<<" "<<it.second<<endl;
        }
        
    }*/
    MSP(n, adj);
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
