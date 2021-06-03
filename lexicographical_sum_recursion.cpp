#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
void recurion(vector<int> &arr, int idx, int target, vector<int> &st, vector<vector<int>> &v)
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
        recurion(arr, idx + 1, target - arr[idx], st, v);
        int temp = idx;
        while (arr[temp] == arr[idx])
        {
            temp++;
        }
        if (temp < arr.size())
            idx = temp;
        else
            return;

        st.pop_back();
    }
    recurion(arr, idx + 1, target, st, v);
}
int solve()
{
    int n, k, temp;
    cin >> n >> k;
    vector<int> arr;
    vector<int> st;
    vector<vector<int>> v;
    repf(i, 0, n)
    {
        cin >> temp;
        arr.emplace_back(temp);
    }
    sort(arr.begin(), arr.end());
    recurion(arr, 0, k, st, v);
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
