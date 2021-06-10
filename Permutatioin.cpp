#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"

void Permutation(vector<int> &arr, int idx, vector<vector<int>> &li)
{
    if (idx == arr.size())
    {
        li.push_back(arr);
        return;
    }
    int n = arr.size();
    repf(i, idx, n)
    {
        swap(arr[idx], arr[i]);
        Permutation(arr, idx + 1, li);
        swap(arr[idx], arr[i]);
    }
}
int solve()
{
    int n, temp;
    cin >> n;
    vector<int> arr;

    vector<vector<int>> li;
    repf(i, 0, n)
    {
        cin >> temp;
        arr.emplace_back(temp);
    }
    Permutation(arr, 0, li);
    for (auto i : li)
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
