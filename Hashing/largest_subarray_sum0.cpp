#include<bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n)
{
    int sum=0;
    int maxid=0;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        sum += A[i];
        if(sum==0){
            maxid= i+1;
        }else{
          if(mpp.find(sum)!=mpp.end()){
              maxid= max(maxid, i-mpp[sum]);
          }else{
              mpp[sum]= i;
          }
        }
    }
    return maxid;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxLen(a,n);
    return 0;
}