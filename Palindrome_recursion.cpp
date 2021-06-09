#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
bool Check(string str, int end, int start)
{
    while (start <= end)
    {
        if (str[start++] != str[end--])
            return false;
    }
    return true;
}
void Recursion(string str, int idx, vector<string> &v, vector<vector<string>> &li)
{
    int n = str.length();
    if (idx == str.length())
    {
        li.push_back(v);
        return;
    }
    repf(i, idx, n)
    {
        if (Check(str, i, idx))
        {
            v.emplace_back(str.substr(idx, i - idx + 1));
            Recursion(str, i + 1, v, li);
            v.pop_back();
        }
    }
}
int solve()
{
    int n, temp;
    cin >> n;
    string str;
    cin >> str;
    vector<string> v;
    vector<vector<string>> li;

    /*repf(i,0,n);
    {
        cin>>temp;
        v.emplace_back(temp);
    }*/
    Recursion(str, 0, v, li);
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
