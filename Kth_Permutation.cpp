#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
void Permutation(vector<int> &arr, int idx, int k, int n, string &ans)
{
    if (arr.size() == 1)
    {
        ans += to_string(arr[0]);
        return;
    }
    int temp = k / fact(n - idx);
    k %= fact(n - idx);
    ans += to_string(arr[temp]);
    arr.erase(arr.begin() + temp);
    Permutation(arr, idx + 1, k, n, ans);
}
int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    string ans;
    repf(i, 0, n) arr.emplace_back(i + 1);
    n--;
    Permutation(arr, 0, k - 1, n, ans);
    cout << ans << endl;
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
