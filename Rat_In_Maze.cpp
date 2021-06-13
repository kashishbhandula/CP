#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
void Rat(int row, int col, vector<vector<int>> &board, int n, string &str)
{
    if (row == n - 1 && col == n - 1)
    {
        cout << str << endl;
        return;
    }
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};
    char val[4] = {'D', 'L', 'R', 'U'};

    repf(i, 0, 4)
    {
        int dpRow = row;
        int dpCol = col;
        dpRow += dy[i];
        dpCol += dx[i];

        if (dpRow < n && dpRow >= 0 && dpCol < n && dpCol >= 0)
        {
            if (board[dpRow][dpCol])
            {
                board[dpRow][dpCol] = 0;
                str += val[i];
                Rat(dpRow, dpCol, board, n, str);
                board[dpRow][dpCol] = 1;
                str.pop_back();
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    string str = "";
    repf(i, 0, n)
    {
        repf(j, 0, n) cin >> board[i][j];
    }
    Rat(0, 0, board, n, str);
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
