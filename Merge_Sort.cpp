#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
void Merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> v;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            v.emplace_back(arr[left++]);
        }
        else
        {
            v.emplace_back(arr[right++]);
        }
    }
    while (left <= mid)
    {
        v.emplace_back(arr[left++]);
    }
    while (right <= high)
    {
        v.emplace_back(arr[right++]);
    }
    for (auto i : v)
    {
        arr[low++] = i;
    }
}
void MergeSort(int arr[], int low, int high)
{
    int mid = ((high - low) >> 1) + low;
    if (low == high)
        return;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}
int solve()
{
    int n;
    cin >> n;
    int arr[n];

    repf(i, 0, n) cin >> arr[i];
    MergeSort(arr, 0, n - 1);
    repf(i, 0, n) cout << arr[i] << " ";
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
