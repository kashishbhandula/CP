#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
void Recursion(vector<int> &v, int idx, int sum, vector<int> &li)
{
    if (idx == v.size())
    {
        li.emplace_back(sum);
        return;
    }
    Recursion(v, idx + 1, sum + v[idx], li);

    Recursion(v, idx + 1, sum, li);
}
int solve()
{
    int n, temp;
    cin >> n;
    vector<int> v;
    vector<int> li;
    repf(i, 0, n)
    {
        cin >> temp;
        v.emplace_back(temp);
    }
    Recursion(v, 0, 0, li);
    for (auto i : li)
        cout << i << " ";
    cout << endl;
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
