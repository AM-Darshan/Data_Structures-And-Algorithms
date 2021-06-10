#include<bits/stdc++.h>
using namespace std;

void sortcolors(int a[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<high){
        if(a[mid]== 0){
            swap(a[mid],a[low]);
            mid++;
            low++;
        }else if(a[mid]== 1){
            mid++;
        }else{
           swap(a[mid],a[high]);
           high--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sortcolors(arr,n);
    return 0;
}