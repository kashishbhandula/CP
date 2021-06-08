#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i, j, k) for (int i = j; i < k; i++)
#define repb(i, j, k) for (int i = j; i > k; i--)
#define endl "\n"
int ReversePair(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int ans = 0;
    while (left <= mid && right <= high)
    {
        while (left <= mid && arr[left] <= 2*arr[right])
        {
            left++;
        }
        ans+= mid - left+1;
        right++;
    }
    return ans;
}
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
int MergeSort(int arr[], int low, int high)
{
    int count = 0;
    int mid = ((high - low) >> 1) + low;
    if (low == high)
        return 0;
    count += MergeSort(arr, low, mid);
    count += MergeSort(arr, mid + 1, high);
    count += ReversePair(arr, low, mid, high);
    Merge(arr, low, mid, high);
    return count;
}
int solve()
{
    int n;
    cin >> n;
    int arr[n];

    repf(i, 0, n) cin >> arr[i];
    int ans=MergeSort(arr, 0, n - 1);
    //repf(i, 0, n) cout << arr[i] << " ";
    //cout << endl;
    cout<<ans<<endl;
    
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
