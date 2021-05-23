#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
bool isPrime[100000007];
int sieve(int n)
{
    n++;
    
    fill(isPrime, isPrime + n, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    isPrime[1] = false;
    /*for (int i = 0; i < n; i++)
    {
        cout << isPrime[i];
    }*/
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    sieve(n);
}
