#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"

bool isSafe(int row, int col, int n, vector<string> &board, vector<char> &lowerDiagnol, vector<char> &upperDiagnol, vector<char> &leftRow)
{
    if (lowerDiagnol[n + row - col] == 'Q')
        return false;
    if (upperDiagnol[row + col] == 'Q')
        return false;
    if (leftRow[row] == 'Q')
        return false;
    return true;
}
void Queen(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<char> &lowerDiagnol, vector<char> &upperDiagnol, vector<char> &leftRow)
{
    if (col == n + 1)
    {
        ans.push_back(board);
        return;
    }
    repf(row, 0, n + 1)
    {
        if (isSafe(row, col, n, board, lowerDiagnol, upperDiagnol, leftRow))
        {
            leftRow[row] = 'Q';
            upperDiagnol[row + col] = 'Q';
            lowerDiagnol[n + row - col] = 'Q';
            board[row][col] = 'Q';
            Queen(col + 1, n, board, ans, lowerDiagnol, upperDiagnol, leftRow);
            board[row][col] = '.';
            leftRow[row] = '.';
            upperDiagnol[row + col] = '.';
            lowerDiagnol[n + row - col] = '.';
        }
    }
}
int solve()
{
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    vector<char> lowerDiagnol((2 * (n - 1)) + 1, '.'); //row+col
    vector<char> upperDiagnol((2 * (n - 1)) + 1, '.'); //n-1+row-col
    vector<char> leftRow(n, '.');
    Queen(0, n - 1, board, ans, lowerDiagnol, upperDiagnol, leftRow);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << endl;
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
