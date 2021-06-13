#include<bits/stdc++.h>
using namespace std;

void rearrange(int a[],int n){
    int i=0,j=n-1;
    while(i<=j){
        if(a[i]<0 && a[j]>0){
            swap(a[i],a[j]);
            i++;
            j--;
        }else if(a[i]>0 && a[j]<0){
            i++;
            j--;
        }else if(a[i]>0){
            i++;
        }else if(a[j]<0){
            j--;
        }
    }
    if(i==0 or i==n){
        return;
    }
    else{
        int k=0;
        while(i<n && k<n){
            swap(a[k],a[i]);
            i++;
            k+=2;
        }
    }
}
int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rearrange(arr,n);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}