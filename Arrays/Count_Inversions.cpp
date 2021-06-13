#include<bits/stdc++.h>
using namespace std;

long long int merge(long long arr[],long long temp[],long long int left,long long int mid ,long long int right){
    
    long long int i,j,k,count=0;
    i=left;
    j=mid;
    k= left;
    while((i<=mid-1)&& (j<=right)){
        if(arr[i] <= arr[j]){
            temp[k++]= arr[i++];
        }else{
            temp[k++]= arr[j++];
            count+= (mid-i);
        }
    }
    while(i<=mid-1){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]= arr[j++];
    }
    for(i= left;i<=right;i++){
        arr[i]= temp[i];
    }
    return count;
}
long long int _mergeSort(long long arr[],long long temp[],long long int left,long long int right){
    long long int mid=0,inv_count=0;
    if(right>left){
        mid = (left + right) / 2;
        inv_count+= _mergeSort(arr,temp,left,mid);
        inv_count+= _mergeSort(arr,temp,mid+1,right);
        inv_count+= merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
    
}
long long int inversionCount(long long arr[], long long N)
{
    long long int count=0;
    long long int temp[N];
    count = _mergeSort(arr,temp,0,N-1);
    return count;
}
int main()
{
    long long n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long int ans= inversionCount(a,n);
    cout<<ans;
    return 0;
}