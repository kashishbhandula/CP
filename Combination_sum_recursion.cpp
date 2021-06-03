#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
vector<vector<int>> v;

void recursion(vector<int> &arr, int idx, int target, vector<int> &st)
{
    if (idx == arr.size())
    {
        if (target == 0)
            v.push_back(st);
        return;
    }
    if (arr[idx] <= target)
    {
        st.push_back(arr[idx]);
        recursion(arr, idx, target - arr[idx], st);
        st.pop_back();
    }
    recursion(arr, idx + 1, target, st);
}
int solve()
{
    int n, k, temp;
    vector<int> st;
    cin >> n >> k;
    vector<int> arr;
    repf(i, 0, n)
    {
        cin >> temp;
        arr.emplace_back(temp);
    }
    recursion(arr, 0, k, st);
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
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
