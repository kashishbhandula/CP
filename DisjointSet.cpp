//Disjoint Set
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
vector<int>Parent(10000);
vector<int>Rank(10000);
void PreCompute(int n)
{
    repf(i,0,n)
    {
        Rank[i]=0;
        Parent[i]=i;
    }

}
int findPar(int node)
{
    if(node==Parent[node])return node;
    return Parent[node]=findPar(Parent[node]);
}
void Union(int x,int y)
{
    int u =findPar(x);
    int v=findPar(y);
    if(Rank[u]<Rank[v]) Parent[u]=v;
    else if (Rank[u]>Rank[v]) Parent[v]=u;
    else
    {
        Parent[v]=u;
        Rank[u]++;
    }
}
void solve()
{
    
    int m,n;
    cin>>m>>n;
    n++;
    PreCompute(n);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    repf(i,0,n)
    {
        cout<<Rank[i]<<endl;
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
    
