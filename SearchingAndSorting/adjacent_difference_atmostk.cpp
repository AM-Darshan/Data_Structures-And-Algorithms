#include<bits/stdc++.h>
using namespace std;


int search(int arr[], int n, int x, int k)
{
    int ans=-1,i=0;
    while(i<n){
        if(arr[i] == x){
            ans=i;
            break;
        }
        i = i+ max(1,abs(arr[i]-x)/k);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x,k;
    cin>>x>>k;
    cout<<search(a,n,x,k);
    return 0;
}