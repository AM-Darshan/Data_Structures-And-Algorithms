#include<bits/stdc++.h>
using namespace std;

long long countTriplets(long long arr[], int n, long long sum)
{
   int count=0;
   sort(arr,arr+n);
   for(int k=0;k<n-2;k++){
       int i=k+1;
       int j=n-1;
       while(i<j){
           int total= arr[i]+arr[j]+arr[k];
           if(total< sum){
               count+= (j-i);
               i++;
           }
           else j--;
       }
   }
   return count;
}
int main()
{
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long sum;
    cin>>sum;
    cout<<countTriplets(a,n,sum);
    return 0;
}