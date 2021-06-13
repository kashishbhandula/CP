#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
vector<int> lps(string str)
{
    int n = str.length();
    int left = 0, right = 1;
    vector<int> lp(n, 0);
    lp[0] = 0;

    while (right < n)
    {
        if (str[right] == str[left])
        {
            left++;
            lp[right] = left;
            right++;
        }
        else
        {
            if (left != 0)
            {
                left = lp[left - 1];
            }
            else
            {
                right++;
            }
        }
    }
    return lp;
}
int kmp(string str, string value)
{
    int ans = 0;
    string s = value + '$' + str;
    vector<int> lp;
    lp = lps(s);
    int n = lp.size();
    int len = value.length();
    repf(i, 0, n)
    {
        if (lp[i] == len)
        {
            cout<<lp[i]<<" ";9
            ans++;
        }
    }
    return ans;
}
int solve()
{
    int n;
    cin >> n;
    string str, value;
    cin >> str;
    cin >> value;
    return kmp(str, value);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        cout << solve() << endl;
    }
}
