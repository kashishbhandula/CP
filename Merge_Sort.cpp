#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define repf(i,j,k) for(int i=j; i<k; i++)
#define repb(i,j,k) for(int i=j; i>k; i--)
#define endl "\n"
void Merge(int arr[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1];
    int right[n2];
    repf(i,0,n1)
    {
        left[i]=arr[low+i];
    }
    repf(i,0,n2)
    {
        right[i]=arr[mid+1+i];
    }
    int i=0,j=0;
    int k=low;
    while(i<n1&&j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[],int low,int high)
{
    if(low>=high)return;
    int mid=((high-low)>>1)+low;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
    
}
int solve()
{
    int n;
    cin>>n;
    int arr[n];
    repf(i,0,n)
    {
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1);
    repf(i,0,n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--)
    {
        solve();
    }
}
